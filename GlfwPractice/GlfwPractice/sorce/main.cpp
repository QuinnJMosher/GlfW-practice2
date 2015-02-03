#include "QuinnFramework.h"

int main() {
	FrameworkInitalize();
	OpenWindow(640, 480, "QuinnFramework");
	SetFontSize(7);
	while (!FrameworkUpdate()) {
		//clear screen
		FrameworkClearScreen();
		//update

		//draw
		DrawString("The quick brown fox jumped over the lazy dog.", 10.0f, 300.0f);
	}
	FrameworkShutdown();

	return 0;
}