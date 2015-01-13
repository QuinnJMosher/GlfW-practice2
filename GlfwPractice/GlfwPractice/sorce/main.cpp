#include "RenderObj.h"

int main() {

	RenderObj renderer = RenderObj();

	renderer.Ininitalize(640, 480, "hello");
	Shape shape = Shape(shapeType::SHPOINT, 640 / 2, 480 / 2, 10, 10, Color(1, 1, 1, 1));

	//main loop
	while (!renderer.ShouldClose()) {
		//clear screen
		renderer.ClearScreen();

		//update

		//draw
		renderer.RenderShape(shape);
		renderer.RenderPoint(100, 100);
	}

	glfwTerminate();
	return 0;
}