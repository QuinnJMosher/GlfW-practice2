#ifndef _Player_h_
#define _Player_h_
#include "Entity.h"
#include "Animation.h"

class Player : public Entity {
public:
	Player();
	Player(glm::vec2 in_pos, glm::vec2 in_size);
	~Player();

	virtual void Update(float in_deltaTime);
	virtual void Draw();

	virtual bool HasColidedWith(Entity *other);
	virtual void CollideWith(Entity *other);

private:
	int hp;
	float speed;

	Animation sprite;
};

#endif