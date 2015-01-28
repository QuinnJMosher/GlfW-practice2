#include "QuinnFramework.h"
#include "tinyxml2.h"

//using tinyxml2::XMLDocument;

int main() {
	FrameworkInitalize();
	OpenWindow(640, 480, "QuinnFramework");

	Shape shape = Shape(shapeType::RECTANGLE, 200, 200, 100, 100);
	tinyxml2::XMLDocument doc;// = new XMLDocument();
	while (!FrameworkUpdate()) {
		//clear screen
		FrameworkClearScreen();
		//update

		//draw
		DrawShape(shape);
	}

	return 0;
}