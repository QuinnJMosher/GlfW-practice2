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
		renderer.RenderPoint(250, 250, Color(1, 1, 1, 1));
		renderer.RenderTriangle(20, 40, 30, 30, Color(1, 1, 1, 1));
		renderer.RenderRectangle(100, 300, 20, 20, Color(1, 1, 1, 1));

	}

	glfwTerminate();
	return 0;
}