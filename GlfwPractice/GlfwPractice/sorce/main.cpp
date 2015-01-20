#include "QuinnFramework.h"

unsigned int loadTexture(const char* a_pFilename, int & a_iWidth, int & a_iHeight, int & a_iBPP);

int main() {

	if (FrameworkInitalize() == -1) {
		return -1;
	}

	if (OpenWindow(640, 480, "hello") == -1) {
		return -1;
	}
	Shape shape = Shape(shapeType::RECTANGLE, 100, 400, 100, 100, Color(1, 1, 1, 0.5f));
	Texture texture = Texture("img_test.png");
	Shape sh2 = Shape(shapeType::RECTANGLE, 120, 380, 100, 100);
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

	glfwTerminate();
	return 0;
}