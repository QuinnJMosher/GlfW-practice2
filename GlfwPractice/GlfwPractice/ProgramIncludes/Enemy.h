#ifndef _Enemy_h_
#define _Enemy_h_
#include <random>
#include <ctime>
#include "Entity.h"
#include "QuinnFramework.h"
#include "Shape.h"
#include "Texture.h"
#include "Globals.h"

class Enemy : public Entity {
public:
	Enemy();
	Enemy(glm::vec2 in_pos);
	~Enemy();

	virtual void Update(float in_deltaTime);
	virtual void Draw();

	virtual void  CollideWith(Entity *other);

	static void DestroyStaticInfo();

private:
	float speed;

	Shape drawBox;
};

#endif