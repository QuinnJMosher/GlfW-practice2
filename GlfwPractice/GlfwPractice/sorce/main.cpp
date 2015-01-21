#include "QuinnFramework.h"

int main() {

	if (FrameworkInitalize() == -1) {
		return -1;
	}

	if (OpenWindow(640, 480, "hello") == -1) {
		return -1;
	}
	Shape shape = Shape(shapeType::RECTANGLE, glm::vec2(100, 400), 100, 100, Color(1, 1, 1, 0.5f));
	Texture texture = Texture("img_test.png");
	Shape sh2 = Shape(shapeType::RECTANGLE, glm::vec2(120, 380), 100, 100);
	Texture tex2 = Texture("test_rect.png");
	//main loop
	while (!FrameworkUpdate()) {
		//clear screen
		FrameworkClearScreen();
		//update
		
		//draw
		DrawSprite(sh2, texture);
		DrawSprite(shape, tex2);
	}

	FrameworkShutdown();
	return 0;
}