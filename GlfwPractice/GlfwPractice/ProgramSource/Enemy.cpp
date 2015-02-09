#include "Enemy.h"

Enemy::Enemy() : Entity() {
	drawBox = Shape(shapeType::RECTANGLE, 0, 0, 50, 50);

	speed = 200;
	isAlive = true;
}
Enemy::Enemy(glm::vec2 in_pos) : Entity(in_pos, glm::vec2(rand() % 90 + 10, rand() % 90 + 10)) {
	srand(time(NULL));
	Color shapeColor = Color((rand() % 99 + 1) / 100.0f, (rand() % 99 + 1) / 100.0f, (rand() % 99 + 1) / 100.0f, 1);
	if (rand() % 5 < 4) {
		drawBox = Shape(shapeType::RECTANGLE, in_pos, size.x, size.y, shapeColor);
	} else {
		drawBox = Shape(shapeType::TRIANGLE, in_pos, size.x, size.y, shapeColor);
	}

	position.y += size.y;
	position.x -= size.x / 2;

	speed = rand() % 350 + 50;
	isAlive = true;
}
Enemy::~Enemy() { 
	DeleteShape(drawBox);
}

void Enemy::Update(float in_deltaTime) {
	position.y -= speed * in_deltaTime;
	if (position.y < 0 - size.y) {
		isAlive = false;
	}
}
void Enemy::Draw() {
	drawBox.SetPos(position);
	DrawShape(drawBox);
}

void  Enemy::CollideWith(Entity *other) {
	isAlive = false;
	GlobalEnemiesKilled++;
}