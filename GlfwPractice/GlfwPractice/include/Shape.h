#ifndef _Shape_h_
#define _Shape_h_
#include "GL/glew.h"
#include "GL/wglew.h"
#include "GLFW/glfw3.h"
#include "Vertex.h"
#include "Color.h"
#include "glm.hpp"

enum shapeType {
	SH_POINT,
	TRIANGLE,
	RECTANGLE
};

class Shape {
public:
	Shape(shapeType in_type, float in_posX, float in_posY, float in_width, float in_height, Color in_color = Color(1, 1, 1, 1));
	Shape(shapeType in_type, glm::vec2 in_pos, float in_width, float in_height, Color in_color = Color(1, 1, 1, 1));
	Shape();
	~Shape();

	void SetColor(float in_r, float in_g, float in_b, float in_a);//takes percent values
	void SetColor(Color in_color);

	void SetPos(float in_posX, float in_posY);
	void SetPos(glm::vec2 in_pos);
	float GetX();
	float GetY();
	glm::vec2 GetPos();

	void SetWidth(float in_Width);
	float GetWidth();

	void SetHeight(float in_Height);
	float GetHeight();

	shapeType GetShape();
	void SyncVBO();
	GLuint GetVBO();
	GLuint GetIBO();

	void SetUVLength(float in_frameWidth, float in_frameHeight);//takes percentage values
	void SetUVStart(float in_startU, float in_startV);//takes percentage values
	void SetUVStart(glm::vec2 in_startUV);//vector should be normalized

	float GetUStart();
	float GetVStart();
	glm::vec2 GetUVStart();

	float GetULength();
	float GetVLength();

private:
	GLuint VBO;
	GLuint IBO;
	shapeType shape;

	void SetIBO();

	bool hasChanged;

	glm::vec2 position;
	float width;
	float height;
	Color color;

	glm::vec2 UVPosition;
	float widthU;
	float heightV;
};

#endif