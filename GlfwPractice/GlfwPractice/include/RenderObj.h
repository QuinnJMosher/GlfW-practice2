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
#include "TextHandeler.h"

class RenderObj {
public:
	RenderObj();
	~RenderObj();

	void Ininitalize();
	void End();
	GLFWwindow* OpenWindow(float in_windowWidth, float in_windowHeight, char* windowName);
	bool ShouldClose();
	void ClearScreen();

	void RenderPoint(float in_x, float in_y, Color in_color = Color(1, 0, 0, 1));
	void RenderTriangle(float in_posX, float in_posY, float in_baseWidth, float in_height, Color in_color = Color(0, 1, 0, 1));
	void RenderRectangle(float in_posX, float in_posY, float in_Width, float in_height, Color in_color = Color(0, 0, 1, 1));
	void RenderShape(Shape in_shape);
	void RenderTexture(Shape in_target, Texture in_source);

	void RenderText(const char* in_text, float in_posX, float in_posY, Color in_color = Color(1, 1, 1, 1));
	void SetFont(const char* in_fontname);
	void SetFontSize(float in_fontSize);

	float GetWindowWidth();
	float GetWindowHeight();

private:

	GLuint CreateShader(GLenum a_eShaderType, const char *a_strShaderFile);
	GLuint CreateProgram(const char *a_vertex, const char *a_frag);
	float* getOrtho(float left, float right, float bottom, float top, float a_fNear, float a_fFar);

	float windowWidth;
	float windowHeight;

	GLFWwindow* window;
	GLuint ProgramFlat;
	GLuint ProgramTextured;
	GLuint MatrixIDFlat;
	float* orthographicProjection;

	GLuint genericVBO;
	TextHandeler* textHandeler;
	float textSize;
};

#endif