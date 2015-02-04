#ifndef _Enemy_h_
#define _Enemy_h_
#include "Entity.h"
#include "QuinnFramework.h"
#include "Shape.h"
#include "Texture.h"
#include "Globals.h"

class Enemy : public Entity {
public:
	Enemy();
	Enemy(glm::vec2 in_pos, glm::vec2 in_size);
	~Enemy();

	virtual void Update(float in_deltaTime);
	virtual void Draw();

	virtual void  CollideWith(Entity *other);

	static void DestroyStaticInfo();

private:
	float speed;

	static Shape* drawBox;
	static Texture* enemyTexture;
};

#endif