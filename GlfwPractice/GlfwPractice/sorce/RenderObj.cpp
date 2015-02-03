#include "RenderObj.h"

RenderObj::RenderObj() { }
RenderObj::~RenderObj() {
	//destroy stuff
}

GLFWwindow* RenderObj::OpenWindow(float in_windowWidth, float in_windowHeight, char* in_windowName) {
	window = glfwCreateWindow(in_windowWidth, in_windowHeight, in_windowName, NULL, NULL);
	assert(window != nullptr);

	glfwMakeContextCurrent(window);

	windowWidth = in_windowWidth;
	windowHeight = in_windowHeight;

	return window;
}

void RenderObj::End() {
	glDeleteProgram(ProgramFlat);
	glDeleteProgram(ProgramTextured);
	glDeleteBuffers(1, &genericVBO);
	//textHandeler->~TextHandeler();
	glfwDestroyWindow(window);
}

void RenderObj::Ininitalize() {

	assert(window != nullptr);

	//start glew
	assert(glewInit() == GLEW_OK);

	//create shader program
	ProgramFlat = CreateProgram("VertexShader.glsl", "FlatFragmentShader.glsl");
	ProgramTextured = CreateProgram("VertexShader.glsl", "TexturedFragmentShader.glsl");

	//find the position of the matrix variable in the shader so we can send info there later
	MatrixIDFlat = glGetUniformLocation(ProgramFlat, "MVP");

	//make ortho projection
	orthographicProjection = getOrtho(0, windowWidth, 0, windowHeight, 0, 100);

	//generate a buffer for the generic buffer
	glGenBuffers(1, &genericVBO);

	//set point size
	glPointSize(2.0f);

	//ready transparency in textures
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//null out textHandeler
	textHandeler = nullptr;
}

float RenderObj::GetWindowWidth() {
	return windowWidth;
}
float RenderObj::GetWindowHeight() {
	return windowHeight;
}

GLuint RenderObj::CreateShader(GLenum a_eShaderType, const char *a_strShaderFile) {
	std::string strShaderCode;
	//open shader file
	std::ifstream shaderStream(a_strShaderFile);
	//if that worked ok, load file line by line
	if (shaderStream.is_open())
	{
		std::string Line = "";
		while (std::getline(shaderStream, Line))
		{
			strShaderCode += "\n" + Line;
		}
		shaderStream.close();
	}

	//convert to cstring
	char const *szShaderSourcePointer = strShaderCode.c_str();

	//create shader ID
	GLuint uiShader = glCreateShader(a_eShaderType);
	//load source code
	glShaderSource(uiShader, 1, &szShaderSourcePointer, NULL);

	//compile shader
	glCompileShader(uiShader);

	//check for compilation errors and output them
	GLint iStatus;
	glGetShaderiv(uiShader, GL_COMPILE_STATUS, &iStatus);
	if (iStatus == GL_FALSE)
	{
		GLint infoLogLength;
		glGetShaderiv(uiShader, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(uiShader, infoLogLength, NULL, strInfoLog);

		const char *strShaderType = NULL;
		switch (a_eShaderType)
		{
		case GL_VERTEX_SHADER: strShaderType = "vertex"; break;
		case GL_FRAGMENT_SHADER: strShaderType = "fragment"; break;
		}

		fprintf(stderr, "Compile failure in %s shader:\n%s\n", strShaderType, strInfoLog);
		delete[] strInfoLog;
	}

	return uiShader;
}

GLuint RenderObj::CreateProgram(const char *a_vertex, const char *a_frag) {
	std::vector<GLuint> shaderList;

	shaderList.push_back(CreateShader(GL_VERTEX_SHADER, a_vertex));
	shaderList.push_back(CreateShader(GL_FRAGMENT_SHADER, a_frag));

	//create shader program ID
	GLuint uiProgram = glCreateProgram();

	//attach shaders
	for (auto shader = shaderList.begin(); shader != shaderList.end(); shader++)
		glAttachShader(uiProgram, *shader);

	//link program
	glLinkProgram(uiProgram);

	//check for link errors and output them
	GLint status;
	glGetProgramiv(uiProgram, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(uiProgram, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(uiProgram, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}

	for (auto shader = shaderList.begin(); shader != shaderList.end(); shader++)
	{
		glDetachShader(uiProgram, *shader);
		glDeleteShader(*shader);
	}

	return uiProgram;
}

float* RenderObj::getOrtho(float left, float right, float bottom, float top, float a_fNear, float a_fFar) {
	float* toReturn = new float[12];
	toReturn[0] = 2.0 / (right - left);;
	toReturn[1] = toReturn[2] = toReturn[3] = toReturn[4] = 0;
	toReturn[5] = 2.0 / (top - bottom);
	toReturn[6] = toReturn[7] = toReturn[8] = toReturn[9] = 0;
	toReturn[10] = 2.0 / (a_fFar - a_fNear);
	toReturn[11] = 0;
	toReturn[12] = -1 * ((right + left) / (right - left));
	toReturn[13] = -1 * ((top + bottom) / (top - bottom));
	toReturn[14] = -1 * ((a_fFar + a_fNear) / (a_fFar - a_fNear));
	toReturn[15] = 1;
	return toReturn;
}

//post init functions
bool RenderObj::ShouldClose() {
	if (glfwWindowShouldClose(window)) {
		return true;
	}
	glfwPollEvents();
	glfwSwapBuffers(window);
	return false;
}

void RenderObj::ClearScreen() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void RenderObj::RenderTriangle(float in_posX, float in_posY, float in_baseWidth, float in_height, Color in_color) {
	//create triangle info
	vertex* triangle = new vertex[3];
	for (int i = 0; i < 3; i++) {
		triangle[i].positions[2] = 0.0f;
		triangle[i].positions[3] = 1.0f;

		triangle[i].colors[0] = in_color.red;
		triangle[i].colors[1] = in_color.green;
		triangle[i].colors[2] = in_color.blue;
		triangle[i].colors[3] = in_color.alpha;
	}

	//red pos
	triangle[0].positions[0] = in_posX + (in_baseWidth / 2);
	triangle[0].positions[1] = in_posY;
	//green pos
	triangle[1].positions[0] = in_posX;
	triangle[1].positions[1] = in_posY - in_height;
	//blue pos
	triangle[2].positions[0] = in_posX + in_baseWidth;
	triangle[2].positions[1] = in_posY - in_height;

	//set generic shape buffer to these properties
	//bind VBO
	glBindBuffer(GL_ARRAY_BUFFER, genericVBO);
	//allocate space for vertices on the graphics card
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex)* 3, NULL, GL_STATIC_DRAW);
	//get pointer to allocated space on the graphics card
	GLvoid* vBuffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	//copy data to graphics card
	memcpy(vBuffer, triangle, sizeof(vertex)* 3);
	//unmap and unbind buffer
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//send our orthographic projection info to the shader
	glUniformMatrix4fv(MatrixIDFlat, 1, GL_FALSE, orthographicProjection);

	//draw
	//enable shaders
	glUseProgram(ProgramFlat);

	glBindBuffer(GL_ARRAY_BUFFER, genericVBO);

	//enable the vertex array states
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(vertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(sizeof(float)* 4));

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void RenderObj::RenderRectangle(float in_posX, float in_posY, float in_Width, float in_height, Color in_color) {
	//create rectangle info
	vertex* rectangle = new vertex[4];
	for (int i = 0; i < 4; i++) {
		rectangle[i].positions[2] = 0.0f;
		rectangle[i].positions[3] = 1.0f;

		rectangle[i].colors[0] = in_color.red;
		rectangle[i].colors[1] = in_color.green;
		rectangle[i].colors[2] = in_color.blue;
		rectangle[i].colors[3] = in_color.alpha;
	}

	//red pos
	rectangle[0].positions[0] = in_posX;
	rectangle[0].positions[1] = in_posY;
	//green pos
	rectangle[1].positions[0] = in_posX;
	rectangle[1].positions[1] = in_posY - in_height;
	//blue pos
	rectangle[2].positions[0] = in_posX + in_Width;
	rectangle[2].positions[1] = in_posY - in_height;
	//white pos
	rectangle[3].positions[0] = in_posX + in_Width;
	rectangle[3].positions[1] = in_posY;

	//set generic shape buffer to these properties
	//bind VBO
	glBindBuffer(GL_ARRAY_BUFFER, genericVBO);
	//allocate space for vertices on the graphics card
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex)* 4, NULL, GL_STATIC_DRAW);
	//get pointer to allocated space on the graphics card
	GLvoid* vBuffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	//copy data to graphics card
	memcpy(vBuffer, rectangle, sizeof(vertex)* 4);
	//unmap and unbind buffer
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//send our orthographic projection info to the shader
	glUniformMatrix4fv(MatrixIDFlat, 1, GL_FALSE, orthographicProjection);

	//draw
	//enable shaders
	glUseProgram(ProgramFlat);

	glBindBuffer(GL_ARRAY_BUFFER, genericVBO);

	//enable the vertex array states
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(vertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(sizeof(float)* 4));

	glDrawArrays(GL_QUADS, 0, 4);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void RenderObj::RenderPoint(float in_x, float in_y, Color in_color) {
	//set values
	vertex* point = new vertex();
	(*point).positions[0] = in_x;
	(*point).positions[1] = in_y;
	(*point).positions[2] = 0.0f;
	(*point).positions[3] = 1.0f;

	(*point).colors[0] = in_color.red;
	(*point).colors[1] = in_color.green;
	(*point).colors[2] = in_color.blue;
	(*point).colors[3] = in_color.alpha;

	//set generic shape buffer to these properties
	//bind VBO
	glBindBuffer(GL_ARRAY_BUFFER, genericVBO);
	//allocate space for vertices on the graphics card
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * 1, NULL, GL_STATIC_DRAW);
	//get pointer to allocated space on the graphics card
	GLvoid* vBuffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	//copy data to graphics card
	memcpy(vBuffer, point, sizeof(vertex) * 1);
	//unmap and unbind buffer
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//send our orthographic projection info to the shader
	glUniformMatrix4fv(MatrixIDFlat, 1, GL_FALSE, orthographicProjection);

	//draw
	//enable shaders
	glUseProgram(ProgramFlat);

	glBindBuffer(GL_ARRAY_BUFFER, genericVBO);

	//enable the vertex array states
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(vertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(sizeof(float)* 4));

	glDrawArrays(GL_POINTS, 0, 1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void RenderObj::RenderShape(Shape in_shape) {
	in_shape.SyncVBO();
	glUseProgram(ProgramFlat);

	glUniformMatrix4fv(MatrixIDFlat, 1, GL_FALSE, orthographicProjection);

	glBindBuffer(GL_ARRAY_BUFFER, in_shape.GetVBO());

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(vertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(sizeof(float) * 4));

	switch (in_shape.GetShape()) {
	case shapeType::SH_POINT:
		glDrawArrays(GL_POINTS, 0, 1);
		break;
	case shapeType::TRIANGLE:
		glDrawArrays(GL_TRIANGLES, 0, 3);
		break;
	case shapeType::RECTANGLE:
		glDrawArrays(GL_QUADS, 0, 4);
		break;
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void RenderObj::RenderTexture(Shape in_target, Texture in_source) {
	in_target.SyncVBO();

	glUniformMatrix4fv(MatrixIDFlat, 1, GL_FALSE, orthographicProjection);
	glUseProgram(ProgramTextured);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, in_target.GetVBO());
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, in_target.GetIBO());
	glBindTexture(GL_TEXTURE_2D, in_source.GetTextureID());

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(vertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(sizeof(float)* 4));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(sizeof(float)* 8));

	

	switch (in_target.GetShape()) {
	case shapeType::TRIANGLE:
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, NULL);
		break;
	case shapeType::RECTANGLE:
		glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, NULL);
		break;
	}

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void RenderObj::RenderText(const char* in_text, float in_posX, float in_posY, Color in_color) {
	if (textHandeler == nullptr) {
		SetFont("Arial2.fnt");
		if (textSize == NULL) {
			SetFontSize(10);
		}
	}
	assert(textHandeler != nullptr);

	float currentX = in_posX;
	for (int i = 0; in_text[i] != '\0'; i++) {
		if (in_text[i] == ' ') {
			currentX += (textSize / 3) * 2;
		} else {
			Character nextChar = textHandeler->GetChar(in_text[i]);

			Shape shape = Shape(shapeType::RECTANGLE, currentX + (nextChar.Xoffset * (textSize / 10)), in_posY - (nextChar.YOffset * (textSize / 10)), textSize * nextChar.width * 30, textSize * nextChar.height * 30, in_color);
			shape.SetUVStart(nextChar.Upos, nextChar.Vpos);
			shape.SetUVLength(nextChar.width, nextChar.height);

			RenderTexture(shape, nextChar.texture);
			currentX += nextChar.advance * (textSize / 10) + (textSize / 2);
		}
	}
}

void RenderObj::SetFont(const char* in_fontname) {
	if (textHandeler == nullptr) {
		textHandeler = new TextHandeler();
	}

	textHandeler->SetFont(in_fontname);
}

void RenderObj::SetFontSize(float in_fontSize) {
	textSize = in_fontSize;
}