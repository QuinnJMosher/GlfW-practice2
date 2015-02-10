#include "QuinnFramework.h"
#include <random>
#include <ctime>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Globals.h"

int main() {
	FrameworkInitalize();
	OpenWindow(640, 700, "FrameworkProgram");

	//seed RNG
	srand(time(NULL));

	//setup actors
	Player player = Player(glm::vec2(GetWindowWidth() / 2, 70 + 35), glm::vec2(100, 70));
	int windowWidthInt = GetWindowWidth() - player.size.x;
	Enemy  *enemy = new Enemy(glm::vec2((rand() % windowWidthInt) + player.size.x / 2, GetWindowHeight()));
	Bullet *bullet = nullptr;

	//setup font
	SetFontSize(5);

	//prepare DeltaTime
	glfwSetTime(0);
	float deltaTime = glfwGetTime();

	//setup key resrictions
	bool kKey = false;
	bool bulletReady = true;

	//start Main loop
	while (!FrameworkUpdate()) {
		//clear screen/ ready time
		deltaTime = glfwGetTime();
		glfwSetTime(0);
		FrameworkClearScreen();

		//update
		player.Update(deltaTime);
		enemy->Update(deltaTime);
		if (bullet != nullptr) {
			bullet->Update(deltaTime);
		}

		//draw text
		char buffer[25];
		sprintf_s(buffer, "Enimies Missed: %d", GlobalEnimiesMissed);
		DrawString(buffer, 5, 25);
		sprintf_s(buffer, "Enimies Hit: %d", GlobalEnemiesKilled);
		DrawString(buffer, GetWindowWidth() - 140, 25);

		//draw Actors
		player.Draw();
		enemy->Draw();
		if (bullet != nullptr) {
			bullet->Draw();
		}

		//collision detection
		if (bullet != nullptr && bullet->HasColidedWith(enemy)) {
			GlobalEnemiesKilled++;
			bullet->isAlive = false;
			enemy->isAlive = false;
		}

		//input reading
		if (GetKeyDown(' ') && bulletReady) {
			bullet = new Bullet(glm::vec2(player.position.x + (player.size.x / 2) - 5, player.position.y));
			bulletReady = false;
		}
		if (GetKeyDown('K')) {
			enemy->isAlive = false;
			kKey = true;
		} else if (GetKeyUp('K')) {
			kKey = false;
		}

		//check actor status
		if (!enemy->isAlive) {
			if (enemy->position.y < 0 - enemy->size.y) {
				GlobalEnimiesMissed++;
			}

			enemy->~Enemy();
			enemy = new Enemy(glm::vec2((rand() % windowWidthInt) + player.size.x / 2, GetWindowHeight()));
		}
		if (bullet != nullptr && !bullet->isAlive) {
			bullet->~Bullet();
			bullet = nullptr;
			bulletReady = true;
		}

		//exit check
		if (GetKeyDown(GLFW_KEY_ESCAPE)) {
			CallExit();
		}
	}
	FrameworkShutdown();

	return 0;
}