#include "GL/glew.h"
#include "GL/wglew.h"
#include "GLFW/glfw3.h"
#include "RenderObj.h"

int main() {

	RenderObj renderer = RenderObj();

	renderer.Ininitalize();
	renderer.OpenWindow(640, 480, "hello");

	//main loop
	while (!renderer.ShouldClose()) {
		//clear screen
		renderer.ClearScreen();

		//update goes here

	}

	glfwTerminate();
	return 0;
}