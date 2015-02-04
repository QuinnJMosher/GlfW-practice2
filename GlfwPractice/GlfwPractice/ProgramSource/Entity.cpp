#include "Entity.h"

Entity::Entity() {
	position = glm::vec2(0, 0);
	size = glm::vec2(1, 1);
}
Entity::Entity(glm::vec2 in_pos, glm::vec2 in_size) {
	position = in_pos;
	size = in_size;
}
Entity::~Entity() { }