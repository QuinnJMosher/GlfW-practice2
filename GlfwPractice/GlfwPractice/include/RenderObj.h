#ifndef _RenderObj_h_
#define _RenderObj_h_
#include "GL/glew.h"
#include "GL/wglew.h"
#include "GLFW/glfw3.h"
#include <cassert>
#include <vector>
#include <string>
#include <fstream>
#include "Color.h"
#include "Vertex.h"
#include "Shape.h"
#include "Texture.h"

class RenderObj {
public:
	RenderObj();
	~RenderObj();

	void Ininitalize(float in_windowHeight, float in_windowWidth, char* windowName);
	bool ShouldClose();
	void ClearScreen();

	void RenderPoint(float in_x, float in_y, Color in_color = Color(1, 0, 0, 1));
	void RenderTriangle(float in_posX, float in_posY, float in_baseWidth, float in_height, Color in_color = Color(0, 1, 0, 1));
	void RenderRectangle(float in_posX, float in_posY, float in_Width, float in_height, Color in_color = Color(0, 0, 1, 1));
	void RenderShape(Shape in_shape);
	void RenderTexture(Shape in_target, Texture in_source);

private:
	void OpenWindow(float in_windowHeight, float in_windowWidth, char* windowName);

	GLuint CreateShader(GLenum a_eShaderType, const char *a_strShaderFile);
	GLuint CreateProgram(const char *a_vertex, const char *a_frag);
	float* getOrtho(float left, float right, float bottom, float top, float a_fNear, float a_fFar);

	GLFWwindow* window;
	GLuint ProgramFlat;
	GLuint ProgramTextured;
	GLuint MatrixIDFlat;
	float* orthographicProjection;

	GLuint genericVBO;

};

#endif