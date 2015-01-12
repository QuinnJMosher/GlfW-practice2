#include "RenderObj.h"

RenderObj::RenderObj() {
	isInitalized = false;
}
RenderObj::~RenderObj() {
	//destroy stuff
}

void RenderObj::OpenWindow(float in_windowHeight, float in_windowWidth, char* in_windowName) {
	assert(isInitalized);
	window = glfwCreateWindow(in_windowHeight, in_windowWidth, in_windowName, NULL, NULL);
	assert(window != nullptr);

	glfwMakeContextCurrent(window);

	//create shader program
	ProgramFlat = CreateProgram("VertexShader.glsl", "FlatFragmentShader.glsl");

	//find the position of the matrix variable in the shader so we can send info there later
	MatrixIDFlat = glGetUniformLocation(ProgramFlat, "MVP");

	//make ortho projection
	orthographicProjection = getOrtho(0, 640, 0, 480, 0, 100);
}

void RenderObj::Ininitalize() {
	//start glfw
	assert(glfwInit());

	//start glew
	assert(glewInit() == GLEW_OK);


}