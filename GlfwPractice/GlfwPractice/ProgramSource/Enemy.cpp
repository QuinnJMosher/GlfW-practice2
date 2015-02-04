#include "Enemy.h"

Shape* Enemy::drawBox = nullptr;
Texture* Enemy::enemyTexture = nullptr;

Enemy::Enemy() : Entity() {
	if (drawBox == nullptr) {
		drawBox = new Shape(shapeType::RECTANGLE, 0, 0, 50, 50);
	}
	if (enemyTexture == nullptr) {
		enemyTexture = new Texture("enemyShip.png");
	}

	speed = 10;
}
Enemy::Enemy(glm::vec2 in_pos, glm::vec2 in_size) : Entity(in_pos, in_size) {
	if (drawBox == nullptr) {
		drawBox = new Shape(shapeType::RECTANGLE, 0, 0, 50, 50);
	}
	if (enemyTexture == nullptr) {
		enemyTexture = new Texture("enemyShip.png");
	}

	speed = 10;
}
Enemy::~Enemy() { }

void Enemy::Update(float in_deltaTime) {
	position.y -= speed * in_deltaTime;
}
void Enemy::Draw() {
	drawBox->SetPos(position);
	DrawSprite(*drawBox, *enemyTexture);
}

void  Enemy::CollideWith(Entity *other) {
	isAlive = false;
	GlobalEnemiesKilled++;
}

void Enemy::DestroyStaticInfo() {
	DeleteShape(*drawBox);
	drawBox->~Shape();
	drawBox = nullptr;

	DeleteTexture(*enemyTexture);
	enemyTexture->~Texture();
	enemyTexture = nullptr;
}