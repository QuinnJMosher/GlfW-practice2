#include "Shape.h"

Shape::Shape(shapeType in_type, float in_posX, float in_posY, float in_width, float in_height, Color in_color) {
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &IBO);
	SetIBO();
	shape = in_type;

	//standard vars
	position = glm::vec2(in_posX, in_posY);
	width = in_width;
	height = in_height;
	color = in_color;

	//texture vars
	UVPosition = glm::vec2(0.0f, 0.0f);
	widthU = 1.0f;
	heightV = 1.0f;

	hasChanged = true;
	SyncVBO();
}
Shape::Shape(shapeType in_type, glm::vec2 in_pos, float in_width, float in_height, Color in_color) {
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &IBO);
	SetIBO();
	shape = in_type;

	//standard vars
	position = in_pos;
	width = in_width;
	height = in_height;
	color = in_color;

	//texture vars
	UVPosition = glm::vec2(0.0f, 0.0f);
	widthU = 1.0f;
	heightV = 1.0f;

	hasChanged = true;
	SyncVBO();
}
Shape::Shape() {

}
Shape::~Shape() { 
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &IBO);

}

void Shape::SetIBO() {
	//bind IBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	//allocate space for index info on the graphics card
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(char), NULL, GL_STATIC_DRAW);
	//get pointer to newly allocated space on the graphics card
	GLvoid* iBuffer = glMapBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_WRITE_ONLY);
	//specify the order we'd like to draw our vertices.
	//In this case they are in sequential order
	for (int i = 0; i < 4; i++)
	{
		((char*)iBuffer)[i] = i;
	}
	//unmap and unbind
	glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Shape::SetColor(float in_r, float in_g, float in_b, float in_a) {
	color = Color(in_r, in_g, in_b, in_a);
	hasChanged = true;
}
void Shape::SetColor(Color in_color) {
	color = in_color;
	hasChanged = true;
}

void Shape::SetPos(float in_posX, float in_posY) {
	position.x = in_posX;
	position.y = in_posY;
	hasChanged = true;
}

void Shape::SetPos(glm::vec2 in_pos) {
	position = in_pos;
	hasChanged = true;
}

float Shape::GetX() {
	return position.x;
}

float Shape::GetY() {
	return position.y;
}

void Shape::SetWidth(float in_Width) {
	width = in_Width;
	hasChanged = true;
}

float Shape::GetWidth() {
	return width;
}

void Shape::SetHeight(float in_Height) {
	height = in_Height;
	hasChanged = true;
}

float Shape::GetHeight() {
	return height;
}

glm::vec2 Shape::GetPos() {
	return position;
}

shapeType Shape::GetShape() {
	return shape;
}

void Shape::SyncVBO() {
	vertex* vert;
	GLvoid* vBuffer;

	if (hasChanged) {
		switch(shape) {
		case shapeType::SH_POINT:
			//ready vert
			vert = new vertex[1];
			vert[0].positions[0] = position.x;
			vert[0].positions[1] = position.y;
			vert[0].positions[2] = 0.0f;
			vert[0].positions[3] = 1.0f;

			vert[0].colors[0] = color.red;
			vert[0].colors[1] = color.green;
			vert[0].colors[2] = color.blue;
			vert[0].colors[3] = color.alpha;

			//set VBO
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * 1, NULL, GL_STATIC_DRAW);
			vBuffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

			memcpy(vBuffer, vert, sizeof(vertex) * 1);

			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			(*vert).~vertex();
			break;

		case shapeType::TRIANGLE:
			//ready vertecies 
			vert = new vertex[3];
			for (int i = 0; i < 3; i++) {
				vert[i].positions[2] = 0;
				vert[i].positions[3] = 1;

				vert[i].colors[0] = color.red;
				vert[i].colors[1] = color.green;
				vert[i].colors[2] = color.blue;
				vert[i].colors[3] = color.alpha;
			}

			vert[0].positions[0] = position.x + (width / 2);
			vert[0].positions[1] = position.y;
			vert[0].uv[0] = UVPosition.x + widthU / 2;
			vert[0].uv[1] = 1.0f - UVPosition.y;

			vert[1].positions[0] = position.x;
			vert[1].positions[1] = position.y - height;
			vert[1].uv[0] = UVPosition.x;
			vert[1].uv[1] = 1.0f - (UVPosition.y + heightV);

			vert[2].positions[0] = position.x + width;
			vert[2].positions[1] = position.y - height;
			vert[2].uv[0] = UVPosition.x + widthU;
			vert[2].uv[1] = 1.0f - (UVPosition.y + heightV);

			//set VBO
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * 3, NULL, GL_STATIC_DRAW);
			vBuffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

			memcpy(vBuffer, vert, sizeof(vertex) * 3);

			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			for (int i = 0; i < 3; i++) {
				vert[i].~vertex();
			}
			break;

		case shapeType::RECTANGLE:
			//ready vertecies 
			vert = new vertex[4];
			for (int i = 0; i < 4; i++) {
				vert[i].positions[2] = 0;
				vert[i].positions[3] = 1;

				vert[i].colors[0] = color.red;
				vert[i].colors[1] = color.green;
				vert[i].colors[2] = color.blue;
				vert[i].colors[3] = color.alpha;
			}

			vert[0].positions[0] = position.x;
			vert[0].positions[1] = position.y;
			vert[0].uv[0] = UVPosition.x;
			vert[0].uv[1] = 1.0f - UVPosition.y;

			vert[1].positions[0] = position.x;
			vert[1].positions[1] = position.y - height;
			vert[1].uv[0] = UVPosition.x;
			vert[1].uv[1] = 1.0f - (UVPosition.y + heightV);

			vert[2].positions[0] = position.x + width;
			vert[2].positions[1] = position.y - height;
			vert[2].uv[0] = UVPosition.x + widthU;
			vert[2].uv[1] = 1.0f - (UVPosition.y + heightV);

			vert[3].positions[0] = position.x + width;
			vert[3].positions[1] = position.y;
			vert[3].uv[0] = UVPosition.x + widthU;
			vert[3].uv[1] = 1.0f - UVPosition.y;

			//set VBO
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertex)* 4, NULL, GL_STATIC_DRAW);
			vBuffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

			memcpy(vBuffer, vert, sizeof(vertex)* 4);

			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			for (int i = 0; i < 4; i++) {
				vert[i].~vertex();
			}
			break;
		}
		hasChanged = false;
	}
}

GLuint Shape::GetVBO() {
	return VBO;
}

GLuint Shape::GetIBO() {
	return IBO;
}

void Shape::SetUVLength(float in_frameWidth, float in_frameHeight) {
	while (in_frameWidth > 1.0f) {
		in_frameWidth--;
	}
	widthU = in_frameWidth;
	while (in_frameHeight > 1.0f) {
		in_frameHeight--;
	}
	heightV = in_frameHeight;
	hasChanged = true;
}

void Shape::SetUVStart(float in_startU, float in_startV) {
	while (in_startU > 1.0f) {
		in_startU--;
	}
	UVPosition.x = in_startU;
	while (in_startV > 1.0f) {
		in_startV--;
	}
	UVPosition.y = in_startV;
	hasChanged = true;
}

void Shape::SetUVStart(glm::vec2 in_startUV) {
	while (in_startUV.x > 1.0f) {
		in_startUV.x--;
	}
	while (in_startUV.y > 1.0f) {
		in_startUV.y--;
	}
	UVPosition = in_startUV;
	hasChanged = true;
}

float Shape::GetUStart() {
	return UVPosition.x;
}

float Shape::GetVStart() {
	return UVPosition.y;
}

glm::vec2 Shape::GetUVStart() {
	return UVPosition;
}

float Shape::GetULength() {
	return widthU;
}

float Shape::GetVLength() {
	return heightV;
}