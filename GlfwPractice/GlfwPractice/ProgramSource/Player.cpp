#include "Player.h"

Player::Player() : Entity() {
	hp = 100;
	speed = 10;
}
Player::Player(glm::vec2 in_pos, glm::vec2 in_size) {

}
Player::~Player();

void Player::Update(float in_deltaTime);
void Player::Draw();

bool Player::HasColidedWith(Entity *other);
void Player::CollideWith(Entity *other);