#include "QuinnFramework.h"
#include "Animation.h"

int main() {

	if (FrameworkInitalize() == -1) {
		return -1;
	}

	if (OpenWindow(640, 480, "hello") == -1) {
		return -1;
	}
	Shape shape = Shape(shapeType::RECTANGLE, glm::vec2(100, 400), 100, 100, Color(1, 1, 1, 0.5f));
	Texture texture = Texture("img_test.png");
	Shape sh2 = Shape(shapeType::RECTANGLE, glm::vec2(120, 380), 100, 100);
	Texture tex2 = Texture("test_rect.png");
	Animation animation = Animation(texture, sh2, 3, 3);
	//main loop
	bool qButtonDown = false;
	bool wButtonDown = false;
	while (!FrameworkUpdate()) {
		//clear screen
		FrameworkClearScreen();
		//update
		if (GetKeyDown('Q') && !qButtonDown) {
			animation.NextFrameX();
			qButtonDown = true;
		} else if (GetKeyUp('Q')) {
			qButtonDown = false;
		}
		if (GetKeyDown('W') && !wButtonDown) {
			animation.NextFrameY();
			wButtonDown = true;
		} else if (GetKeyUp('W')) {
			wButtonDown = false;
		}
		//draw
		//DrawSprite(sh2, texture);
		//DrawSprite(shape, tex2);
		DrawAnimation(animation);
	}

	FrameworkShutdown();
	return 0;
}