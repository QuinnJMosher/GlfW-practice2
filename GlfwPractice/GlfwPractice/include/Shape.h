#ifndef _Shape_h_
#define _Shape_h_
#include "GL/glew.h"
#include "GL/wglew.h"
#include "GLFW/glfw3.h"
#include "Vertex.h"
#include "Color.h"

enum shapeType {
	POINT,
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

private:
	GLuint VBO;
	shapeType shape;

	bool hasChanged;

	float posX;
	float posY;
	float width;
	float height;
	Color color;
};

#endif