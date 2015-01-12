#ifndef _RenderObj_h_
#define _RenderObj_h_
#include "GL/glew.h"
#include "GL/wglew.h"
#include "GLFW/glfw3.h"
#include <cassert>

class RenderObj {
public:
	RenderObj();
	~RenderObj();

	void OpenWindow(float in_windowHeight, float in_windowWidth, char* windowName);
	void Ininitalize();
	//update/swapbuffers?
	void ClearScreen();

	void RenderTriangle(float in_posX, float in_posY, float in_baseWidth, float in_height);

private:
	bool isInitalized;

	GLFWwindow* window;
	GLuint ProgramFlat;
	GLuint MatrixIDFlat;
	float* orthographicProjection;

};

#endif