#include "EnermyFinalBoss1Sprite.h"
#include "EnermyFinalBoss1StandingState.h"

EnermyFinalBoss1Sprite:: EnermyFinalBoss1Sprite(int respawnX, int respawnY)
{
	
	pData = new EnermyData();

	pData -> botName = "finalboss1";

	pData-> x  = respawnX;

	pData-> y  = respawnY;

	pData->ppTextureArrays = new TextureArray* [ 2 ];

	pData->ppTextureArrays[0 ] = new TextureArray("Resources\\Sprites\\Enermy" ,"finalboss1","", 3, 8);

	pData->ppTextureArrays[ 0 ] -> setAnchorPoint(0.5f, 0.5f );

	pData ->ppTextureArrays[ 1 ] = new TextureArray("Resources\\Sprites\\Explosions", "explosion","", 6, 8);

	pData->ppTextureArrays[ 1 ] -> setAnchorPoint(0.5f, 0.5f );

	pData ->dir = Direction::createRight();

	pData ->pState = new EnermyFinalBoss1StandingState(pData);

	pData -> isDesTroyed = false;

	pData -> isHittable = true;

	pData -> isThrougable = true;

	pData -> HP = 3;

	pData ->body = RectF( -6.5f, -6.5f, 13.0f, 13.0f);
}
 void EnermyFinalBoss1Sprite::draw( Camera* cam)
 {
	 if( pData -> dir.isRight())
		pData->ppTextureArrays[ pData->iCurrentArr ] -> draw(pData -> x, pData -> y , cam);
	else if( pData -> dir.isLeft())
		pData->ppTextureArrays[ pData->iCurrentArr ] -> drawFlipX(pData -> x, pData -> y , cam);
 }
 void EnermyFinalBoss1Sprite:: update()
 {
	 pData ->pState	 ->onUpdate();
 }
EnermyFinalBoss1Sprite::~EnermyFinalBoss1Sprite()
{
	
}
