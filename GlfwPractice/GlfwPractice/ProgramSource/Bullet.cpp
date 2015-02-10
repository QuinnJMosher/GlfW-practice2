#include "Bullet.h"

Shape* Bullet::bulletDrawBox = nullptr;
Texture* Bullet::bulletTex = nullptr;

Bullet::Bullet() : Entity() {
	if (bulletDrawBox == nullptr) {
		bulletDrawBox = new Shape(shapeType::RECTANGLE, glm::vec2(0, 0), 10, 30);
	}
	if (bulletTex == nullptr) {
		bulletTex = new Texture("ProgramAssets/laserGreen.png");
	}

	speed = 1500;
}
Bullet::Bullet(glm::vec2 in_pos) : Entity(in_pos, glm::vec2(10, 30)) {
	if (bulletDrawBox == nullptr) {
		bulletDrawBox = new Shape(shapeType::RECTANGLE, glm::vec2(0, 0), 10, 30);
	}
	if (bulletTex == nullptr) {
		bulletTex = new Texture("ProgramAssets/laserGreen.png");
	}

	speed = 1500;
}
Bullet::~Bullet() { }

void Bullet::Update(float in_deltaTime) {
	position.y +=  speed * in_deltaTime;
	if (position.y > GetWindowHeight()) {
		this->isAlive = false;
	}
}
void Bullet::Draw() {
	bulletDrawBox->SetPos(position);
	DrawSprite(*bulletDrawBox, *bulletTex);
}

void Bullet::CollideWith(Entity* other) {
	this->isAlive = false;
	other->isAlive = false;
}

void Bullet::DeleteStaticInfo() {
	if (bulletDrawBox != nullptr) {
		DeleteShape(*bulletDrawBox);
		bulletDrawBox->~Shape();
		bulletDrawBox = nullptr;
	}

	if (bulletTex != nullptr) {
		DeleteTexture(*bulletTex);
		bulletTex->~Texture();
		bulletTex = nullptr;
	}
}