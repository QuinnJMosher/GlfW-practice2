#ifndef _Entity_h_
#define _Entity_h_
#include "glm.hpp"

class Entity {
public:
	Entity();
	Entity(glm::vec2 in_pos, glm::vec2 in_size);
	~Entity();

	virtual void Update(float in_deltaTime) = 0;
	virtual void Draw() = 0;

	virtual bool HasColidedWith(Entity *other) = 0;
	virtual void CollideWith(Entity *other) = 0;

protected:
	glm::vec2 position;
	glm::vec2 size;
};

#endif