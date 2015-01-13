#include "Shape.h"

Shape::Shape(shapeType in_type, float in_posX, float in_posY, float in_width, float in_height, Color in_color) {
	glGenBuffers(1, &VBO);
	shape = in_type;

	posX = in_posX;
	posY = in_posY;
	width = in_width;
	height = in_height;
	color = in_color;

	hasChanged = true;
	SyncVBO();
}
Shape::~Shape() { /*destroy buffer?*/ }

void Shape::SetColor(float in_r, float in_g, float in_b, float in_a) {
	color = Color(in_r, in_g, in_b, in_a);
	hasChanged = true;
}

void Shape::SetPos(float in_posX, float in_posY) {
	posX = in_posX;
	posY = in_posY;
	hasChanged = true;
}

float Shape::GetX() {
	return posX;
}

float Shape::GetY() {
	return posY;
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

shapeType Shape::GetShape() {
	return shape;
}

void Shape::SyncVBO() {
	vertex* vert;
	GLvoid* vBuffer;

	if (hasChanged) {
		switch(shape) {
		case shapeType::SHPOINT:
			//ready vert
			vert = new vertex[1];
			vert[0].positions[0] = posX;
			vert[0].positions[1] = posY;
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

			vert[0].positions[0] = posX + (width / 2);
			vert[0].positions[1] = posY;

			vert[1].positions[0] = posX;
			vert[1].positions[1] = posY - height;

			vert[2].positions[0] = posX + width;
			vert[2].positions[1] = posY - height;

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

			vert[0].positions[0] = posX;
			vert[0].positions[1] = posY;

			vert[1].positions[0] = posX;
			vert[1].positions[1] = posY - height;

			vert[2].positions[0] = posX + width;
			vert[2].positions[1] = posY - height;

			vert[3].positions[0] = posX + width;
			vert[3].positions[1] = posY;

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