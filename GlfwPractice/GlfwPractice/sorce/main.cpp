#include "QuinnFramework.h"
#include "Font.h"

int main() {
	FrameworkInitalize();
	OpenWindow(640, 480, "QuinnFramework");

	Font font = Font("arial.ttf", 40);
	Shape shape = Shape(shapeType::RECTANGLE, 200, 200, 100, 100);
	DrawShape(shape);
	while (!FrameworkUpdate()) {
		//clear screen
		FrameworkClearScreen();
		//update

		//draw
		DrawChar(font, 'A');
	}

	return 0;
}