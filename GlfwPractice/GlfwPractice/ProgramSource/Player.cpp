#include "Player.h"

Player::Player() : Entity() {
	speed = 300;

	sprite = Animation("ProgramAssets/player.png", position.x, position.y, size.x, size.y, 1, 1);
}
Player::Player(glm::vec2 in_pos, glm::vec2 in_size) : Entity(in_pos, in_size) {
	speed = 300;

	sprite = Animation("ProgramAssets/player.png", position.x, position.y, size.x, size.y, 1, 1);
}
Player::~Player() {
	DeleteAnimation(sprite);
}

void Player::Update(float in_deltaTime) {
	if (GetKeyDown('A')) {
		position.x -= speed * in_deltaTime;
		if (position.x < 0) {
			position.x = 0;
		}
	}
	if (GetKeyDown('D')) {
		position.x += speed * in_deltaTime;
		if (position.x + size.x > GetWindowWidth()) {
			position.x = GetWindowWidth() - size.x;
		}
	}
}
void Player::Draw() {
	sprite.MoveTo(position.x, position.y);
	DrawAnimation(sprite);
}

void Player::CollideWith(Entity *other) {
	other->isAlive = false;
	//GlobalTimesHit++;
}