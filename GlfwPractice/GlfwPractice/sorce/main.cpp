#include "RenderObj.h"

int main() {
	RenderObj renderer = RenderObj();
	renderer.Ininitalize();
	renderer.OpenWindow (640, 480, "hello");
	while (!renderer.ShouldClose()) {
		//clear screen
		renderer.ClearScreen();
		//update

		//draw
		renderer.RenderRectangle(100, 100, 100, 100);
	}

	return 0;
}