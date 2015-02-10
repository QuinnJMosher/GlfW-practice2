#ifndef _Bullet_h_
#define _Bullet_h_
#include "Entity.h"
#include "QuinnFramework.h"
#include "Shape.h"
#include "Texture.h"

class Bullet : public Entity {
public:
	Bullet();
	Bullet(glm::vec2 in_pos);
	~Bullet();

	virtual void Update(float in_deltaTime);
	virtual void Draw();

	virtual void CollideWith(Entity* other);

	static void DeleteStaticInfo();
private:
	float speed;

	static Shape* bulletDrawBox;
	static Texture* bulletTex;
};

#endif