#include "QuinnFramework.h"
#include "Player.h"
#include "Enemy.h"
#include "Globals.h"

int main() {
	FrameworkInitalize();
	OpenWindow(640, 700, "FrameworkProgram");
	
	Player player = Player(glm::vec2(GetWindowWidth() / 2, 70 + 5), glm::vec2(100, 70));
	Enemy  enemy = Enemy();
	while (!FrameworkUpdate()) {
		//clear screen
		FrameworkClearScreen();
		//update
		player.Update(1.0f / 60);
		//draw
		player.Draw();

		//exit check
		if (GetKeyDown(GLFW_KEY_ESCAPE)) {
			CallExit();
		}
	}
	FrameworkShutdown();

	return 0;
}