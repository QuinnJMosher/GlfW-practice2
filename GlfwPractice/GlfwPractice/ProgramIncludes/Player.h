#ifndef _Player_h_
#define _Player_h_
#include "Entity.h"
#include "QuinnFramework.h"
#include "Globals.h"

class Player : public Entity {
public:
	Player();
	Player(glm::vec2 in_pos, glm::vec2 in_size);
	~Player();

	virtual void Update(float in_deltaTime);
	virtual void Draw();

	virtual void CollideWith(Entity *other);

private:
	float speed;

	Animation sprite;
};

#endif