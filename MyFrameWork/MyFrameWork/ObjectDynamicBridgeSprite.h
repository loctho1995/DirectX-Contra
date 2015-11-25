#pragma once
#include "ObjectSprite.h"

class ObjectDynamicBridgeSprite : public ObjectSprite
{
public:
	ObjectDynamicBridgeSprite(float x, float y);
	~ObjectDynamicBridgeSprite();
	static void loadResources();
	virtual void draw(Camera* cam);
	//virtual CollisionRectF& getCollisionRect();
	virtual void update();
};

