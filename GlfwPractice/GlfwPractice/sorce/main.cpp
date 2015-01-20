//#include "RenderObj.h"
#include "FrameworkInstance.h"

unsigned int loadTexture(const char* a_pFilename, int & a_iWidth, int & a_iHeight, int & a_iBPP);

int main() {

	//RenderObj renderer = RenderObj();
	FrameworkInstance::Init();

	assert(glfwInit());
	FrameworkInstance::GetFrwkInst()->renderer.OpenWindow(640, 480, "hello");
	FrameworkInstance::GetFrwkInst()->renderer.Ininitalize();
	Shape shape = Shape(shapeType::RECTANGLE, 0, 100, 100, 100, Color(1, 1, 1, 1));
	Texture texture = Texture("img_test.png");
	//main loop
	while (!FrameworkInstance::GetFrwkInst()->renderer.ShouldClose()) {
		//clear screen
		FrameworkInstance::GetFrwkInst()->renderer.ClearScreen();

		//update

		//draw
		FrameworkInstance::GetFrwkInst()->renderer.RenderTexture(shape, texture);
	}

	glfwTerminate();
	return 0;
}