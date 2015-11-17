#include "ObjectDynamicBridgeSprite.h"
#include "DynamicBridgeMovingState.h"

ObjectDynamicBridgeSprite::ObjectDynamicBridgeSprite(float respawnX, float respawnY)
{
	pData = new ObjectData();
	pData -> x = respawnX;
	pData -> y = respawnY;
	pData -> isHittable = false;
	pData -> isAffectble = true;
	pData -> isDesTroyed = false;
	pData -> isPlayerCollisionable = true;
	pData -> isEnemyCollisionable = false;
	pData -> objectName = "dynamicbridge";
	pData ->dir = Direction::createRight();
	pData->ppTextureArrays = new TextureArray* [ 1 ];
	pData->ppTextureArrays[0 ] = new TextureArray("Resources\\Sprites" ,"dynamicbridge","", 1, 60);
	pData->ppTextureArrays[0 ] -> setAnchorPoint(0.0f, 0.0f);
	pData ->body = RectF( 0, 1.0f, 32.0f, 12.0f);
	pData -> pState = new DynamicBridgeMovingState(pData);
}


ObjectDynamicBridgeSprite::~ObjectDynamicBridgeSprite()
{
}

void ObjectDynamicBridgeSprite:: draw(Camera* cam)
{
	pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
}

void ObjectDynamicBridgeSprite :: loadResources()
{
	TextureArray* temp = new TextureArray("Resources\\Sprites" ,"dynamicbridge","", 1, 60);

	delete temp;
}

//CollisionRectF& ObjectDynamicBridgeSprite :: getCollisionRect()
//{
//	return pData -> collisionRect;
//}

void ObjectDynamicBridgeSprite :: update()
{
	ObjectSprite::update();
	
}
