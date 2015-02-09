#ifndef _Bullet_h_
#define _Bullet_h_
#include "Entity.h"

class bullet : public Entity {
public:
	Bullet();
	Bullet(glm::vec2 in_pos);
	~Bullet();

	virtual void Update(float in_deltaTime);
	virtual void Draw();

	virtual void CollideWith(Entity* other);

	static void DeleteStaticInfo();
private:
	static Shape bullteDrawBox;
	static Texture bulletTex;
};

#endif