#include "EnemyMineSprite.h"
#include "EnemyMineFallingState.h"
#include "Sound.h"
EnemyMineSprite::EnemyMineSprite(int respawnX, int respawnY)
{
	pData = new EnermyData();
	pData -> x = respawnX;
	pData -> y = respawnY;
	pData -> respawnX = respawnX;
	pData -> respawnY = respawnY;
	pData -> isHittable = false;
	pData -> isThrougable = false;
	pData -> botName = "mine";
	pData ->dir = Direction::createRight();
	pData->ppTextureArrays = new TextureArray* [ 2 ];
	pData->ppTextureArrays[0 ] = new TextureArray("Resources\\Sprites\\Enermy" ,"mine","", 8 , 4);
	pData->ppTextureArrays[0 ] -> setAnchorPoint(0.5f, 1.0f);
	pData->ppTextureArrays[1 ] = new TextureArray("Resources\\Sprites\\Explosions" ,"explosiontype1","", 3 , 8);
	pData->ppTextureArrays[1 ] -> setAnchorPoint(0.5f, 1.0f);
	pData ->body = RectF( -14.0f / 2, -14.0f, 14.0f, 14.0f);
	pData -> pState = new EnemyMineFallingState(pData);
	
}


void EnemyMineSprite:: loadResources()
{
	TextureArray* temp;
	temp = new TextureArray("Resources\\Sprites\\Enermy" ,"mine","", 8 , 6);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\Explosions" ,"explosiontype1","", 3 , 8);
	delete temp;
}


EnemyMineSprite::~EnemyMineSprite(void)
{
}
