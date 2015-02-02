#include "QuinnFramework.h"

int main() {
	FrameworkInitalize();
	OpenWindow(640, 480, "QuinnFramework");

	Shape shape2 = Shape(shapeType::RECTANGLE, 100, 100, 100, 100);
	Shape shape3 = Shape(shapeType::RECTANGLE, 100, 200, 100, 100);
	Texture text = Texture("img_test.png");
	Texture text2 = Texture("test_rect.png");
	SetFontSize(10);
	while (!FrameworkUpdate()) {
		//clear screen
		FrameworkClearScreen();
		//update

		//draw
		
		//DrawSprite(shape3, text2);
		DrawString("ABCDEFG", 100.0f, 100.0f);
		//DrawString("B", 150.0f, 100.0f);
		//DrawString("C", 200.0f, 100.0f);
	
	}

	return 0;
}