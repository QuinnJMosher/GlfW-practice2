#include "RenderObj.h"

unsigned int loadTexture(const char* a_pFilename, int & a_iWidth, int & a_iHeight, int & a_iBPP);

int main() {

	RenderObj renderer = RenderObj();

	assert(glfwInit());
	renderer.OpenWindow(640, 480, "hello");
	renderer.Ininitalize();
	Shape shape = Shape(shapeType::RECTANGLE, 0, 100, 100, 100, Color(1, 1, 1, 1));
	Texture texture = Texture("img_test.png");
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