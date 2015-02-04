#include "Entity.h"

Entity::Entity() {
	position = glm::vec2(0, 0);
	size = glm::vec2(1, 1);

	isAlive = true;
}
Entity::Entity(glm::vec2 in_pos, glm::vec2 in_size) {
	position = in_pos;
	size = in_size;
	
	isAlive = true;
}
Entity::~Entity() { }

bool Entity::HasColidedWith(Entity *other) {
	if (position.x > other->position.x + other->size.x || other->position.x > position.x + size.x) {
		return false;
	}
	if (position.y > other->position.y + other->size.y || other->position.y > position.y + size.y) {
		return false;
	}
	return true;
}