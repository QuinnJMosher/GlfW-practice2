#include "GL/glew.h"
#include "GL/wglew.h"
#include "GLFW/glfw3.h"
#include <vector>
#include <string>
#include <fstream>

//prototypes
float* getOrtho(float left, float right, float bottom, float top, float a_fNear, float a_fFar);
GLuint CreateShader(GLenum a_eShaderType, const char *a_strShaderFile);
GLuint CreateProgram(const char *a_vertex, const char *a_frag);

int main() {
	//start glfw
	if (!glfwInit()) {
		return -1;
	}

	//make window
	GLFWwindow* window;
	window = glfwCreateWindow(640, 480, "hello", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	//start glew
	if (glewInit() != GLEW_OK) {
		glfwTerminate();
		return -1;
	}

	//create shader program
	GLuint ProgramFlat = CreateProgram("VertexShader.glsl", "FlatFragmentShader.glsl");

	//find the position of the matrix variable in the shader so we can send info there later
	GLuint MatrixIDFlat = glGetUniformLocation(ProgramFlat, "MVP");

	//make ortho projection
	float* orthographicProjection = getOrtho(0, 640, 0, 480, 0, 100);

	//main loop
	while (!glfwWindowShouldClose(window)) {
		//clear screen
		glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//update goes here

	}

	glfwTerminate();
	return 0;
}

float* getOrtho(float left, float right, float bottom, float top, float a_fNear, float a_fFar)
{
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

GLuint CreateShader(GLenum a_eShaderType, const char *a_strShaderFile)
{
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

GLuint CreateProgram(const char *a_vertex, const char *a_frag)
{
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