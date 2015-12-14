#include "EnermyFinalBoss1Sprite.h"
#include "EnermyFinalBoss1StandingState.h"
#include "Sound.h"
EnermyFinalBoss1Sprite:: EnermyFinalBoss1Sprite(int respawnX, int respawnY)
{
	
	pData = new EnermyData();

	pData -> botName = "finalboss1";

	pData-> x  = respawnX;

	pData-> y  = respawnY;

	pData->ppTextureArrays = new TextureArray* [ 2 ];

	pData->ppTextureArrays[0 ] = new TextureArray("Resources\\Sprites\\Enermy" ,"finalboss1","", 3, 8);

	pData->ppTextureArrays[ 0 ] -> setAnchorPoint(0.5f, 0.5f );

	pData ->ppTextureArrays[ 1 ] = new TextureArray("Resources\\Sprites\\Explosions", "explosion","", 3, 8);

	pData->ppTextureArrays[ 1 ] -> setAnchorPoint(0.5f, 0.5f );

	pData ->dir = Direction::createRight();

	pData ->pState = new EnermyFinalBoss1StandingState(pData);

	pData -> isDesTroyed = false;

	pData -> isHittable = true;

	pData -> isThrougable = true;

	pData -> score = 10000;

	pData -> HP = 32;

	pData ->body = RectF( -6.5f, -6.5f, 13.0f, 13.0f);

	Sound :: getInstance() -> play("warning", false , 1);
}
 
EnermyFinalBoss1Sprite::~EnermyFinalBoss1Sprite()
{
	
}

void EnermyFinalBoss1Sprite:: playBeShootedEffect()
{
	Sound :: getInstance() -> play("beShooted", false , 1);
}
void EnermyFinalBoss1Sprite :: loadResources()
{
	TextureArray* temp = new TextureArray("Resources\\Sprites\\Enermy" ,"finalboss1","", 3, 8);

	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion","", 6, 8);

	delete temp;
}


