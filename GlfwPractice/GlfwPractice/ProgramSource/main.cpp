#include "QuinnFramework.h"
#include <random>
#include <ctime>
#include "Player.h"
#include "Enemy.h"
#include "Globals.h"

int main() {
	FrameworkInitalize();
	OpenWindow(640, 700, "FrameworkProgram");

	srand(time(NULL));
	
	Player player = Player(glm::vec2(GetWindowWidth() / 2, 70 + 35), glm::vec2(100, 70));
	int windowWidthInt = GetWindowWidth() - player.size.x;
	Enemy  *enemy = new Enemy(glm::vec2((rand() % windowWidthInt) + player.size.x / 2, GetWindowHeight()));
	SetFontSize(5);
	glfwSetTime(0);
	float deltaTime = glfwGetTime();
	bool kKey = false;
	while (!FrameworkUpdate()) {
		//clear screen
		deltaTime = glfwGetTime();
		glfwSetTime(0);
		FrameworkClearScreen();
		//update
		player.Update(deltaTime);
		enemy->Update(deltaTime);

		//draw
		char buffer[25];
		sprintf_s(buffer, "Enimies Missed: %d", GlobalEnimiesMissed);
		DrawString(buffer, 5, 25);
		player.Draw();
		enemy->Draw();

		if (GetKeyDown('K') && !kKey) {
			enemy->isAlive = false;
			kKey = true;
		} else if (GetKeyUp('K')) {
			kKey = false;
		}
		if (enemy->isAlive == false) {
			GlobalEnimiesMissed++;
			enemy->~Enemy();
			enemy = new Enemy(glm::vec2((rand() % windowWidthInt) + player.size.x / 2, GetWindowHeight()));
		}

		//exit check
		if (GetKeyDown(GLFW_KEY_ESCAPE)) {
			CallExit();
		}
	}
	FrameworkShutdown();

	return 0;
}