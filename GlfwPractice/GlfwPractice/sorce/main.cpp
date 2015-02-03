#include "QuinnFramework.h"

int main() {
	FrameworkInitalize();
	OpenWindow(640, 480, "QuinnFramework");
	SetFontSize(20);
	while (!FrameworkUpdate()) {
		//clear screen
		FrameworkClearScreen();
		//update
		anim.NextFrameX();

		//draw
		DrawString("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10.0f, 100.0f);
		DrawString("abcdefghijklmnopqrstuvwxyz", 10.0f, 400.0f);
	}

	return 0;
}