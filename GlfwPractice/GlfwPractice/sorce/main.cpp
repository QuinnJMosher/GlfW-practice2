#include "GL/glew.h"
#include "GL/wglew.h"
#include "GLFW/glfw3.h"
#include "RenderObj.h"

int main() {

	RenderObj renderer = RenderObj();

	renderer.Ininitalize(640, 480, "hello");

	//main loop
	while (!renderer.ShouldClose()) {
		//clear screen
		renderer.ClearScreen();

		//update

		//draw
		renderer.RenderTriangle(100, 100, 30, 30);
		renderer.RenderRectangle(320, 240, 40, 50);

	}

	glfwTerminate();
	return 0;
}