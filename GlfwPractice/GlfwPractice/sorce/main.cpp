#include "RenderObj.h"

int main() {

	RenderObj renderer = RenderObj();

	renderer.Ininitalize(640, 480, "hello");
	Shape shape = Shape(shapeType::TRIANGLE, 640 / 2, 480 / 2, 40, 40, Color(1, 1, 1, 1));

	//main loop
	while (!renderer.ShouldClose()) {
		//clear screen
		renderer.ClearScreen();

		//update

		//draw
		renderer.RenderShape(shape);
	}

	glfwTerminate();
	return 0;
}