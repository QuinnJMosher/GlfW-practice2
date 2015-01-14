#include "RenderObj.h"

int main() {

	RenderObj renderer = RenderObj();

	renderer.Ininitalize(640, 480, "hello");
	Shape shape = Shape(shapeType::RECTANGLE, 640 / 2, 480 / 2, 100, 100, Color(1, 1, 1, 1));
	Texture texture = Texture("test_rect.png", 256, 256, 32);
	//Texture texture = Texture("img_rect.png", 50, 50, 4);
	//main loop
	while (!renderer.ShouldClose()) {
		//clear screen
		renderer.ClearScreen();

		//update

		//draw
		renderer.RenderTexture(shape, texture);
	}

	glfwTerminate();
	return 0;
}