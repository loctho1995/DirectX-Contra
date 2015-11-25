#include "EnemyBlazerSprite.h"
#include "BlazerMovingState.h"

EnemyBlazerSprite::EnemyBlazerSprite(int respawnX, int respawnY)
{
	pData = new EnermyData();
	pData -> x = respawnX;
	pData -> y = respawnY;
	pData -> isHittable = false;
	pData -> isThrougable = false;
	pData -> botName = "blazer";
	pData ->dir = Direction::createRight();
	pData->ppTextureArrays = new TextureArray* [ 1 ];
	pData->ppTextureArrays[0 ] = new TextureArray("Resources\\Sprites" ,"blazer","", 2, 6);
	pData->ppTextureArrays[0 ] -> setAnchorPoint(0.5f, 1.0f);
	pData ->body = RectF( -14.0f / 2, -14.0f, 14.0f, 14.0f);
	pData -> pState = new BlazerMovingState(pData);
}


EnemyBlazerSprite::~EnemyBlazerSprite()
{
}

void EnemyBlazerSprite :: loadResources()
{
	TextureArray* temp = new TextureArray("Resources\\Sprites" ,"blazer","", 2, 4);

	delete temp;
}


