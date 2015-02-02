#include "QuinnFramework.h"

int main() {
	FrameworkInitalize();
	OpenWindow(640, 480, "QuinnFramework");

	Shape shape = Shape(shapeType::RECTANGLE, 200, 200, 100, 100);
	while (!FrameworkUpdate()) {
		//clear screen
		FrameworkClearScreen();
		//update

		//draw
		DrawShape(shape);
	}

	return 0;
}