#include "QuinnFramework.h"

int main() {
	FrameworkInitalize();
	OpenWindow(640, 480, "QuinnFramework");
	SetFontSize(10);
	while (!FrameworkUpdate()) {
		//clear screen
		FrameworkClearScreen();
		//update

		//draw
		DrawString("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10.0f, 300.0f);
		DrawString("abcdefghijklmnopqrstuvwxyz", 10.0f, 400.0f);
		DrawString("!@#$%^&*()_+{}[]|\\:;\"'?/.,<>", 10.0f, 200.0f);
	}

	return 0;
}