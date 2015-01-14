#ifndef _Shape_h_
#define _Shape_h_
#include "GL/glew.h"
#include "GL/wglew.h"
#include "GLFW/glfw3.h"
#include "Vertex.h"
#include "Color.h"

enum shapeType {
	SHPOINT,
	TRIANGLE,
	RECTANGLE
};

class Shape {
public:
	Shape(shapeType in_type, float in_posX, float in_posY, float in_width, float in_height, Color in_color = Color(1, 1, 1, 1));
	~Shape();

	void SetColor(float in_r, float in_g, float in_b, float in_a);

	void SetPos(float in_posX, float in_posY);
	float GetX();
	float GetY();

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

	float GetUStart();
	float GetVStart();

	float GetULength();
	float GetVLength();

private:
	GLuint VBO;
	GLuint IBO;
	shapeType shape;

	void SetIBO();

	bool hasChanged;

	float posX;
	float posY;
	float width;
	float height;
	Color color;

	float startU;
	float startV;
	float widthU;
	float heightV;
};

#endif