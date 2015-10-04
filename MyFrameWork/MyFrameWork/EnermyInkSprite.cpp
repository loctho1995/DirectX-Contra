#include "EnermyInkSprite.h"

EnermyInkSprite :: EnermyInkSprite( int respawnX, int respawnY)
{
	pData = new EnermyData();

	pData->x  = respawnX;

	pData->y  = respawnY;

	pData->ppTextureArrays = new TextureArray* [ 2 ];

	pData->ppTextureArrays[0 ] = new TextureArray("Resources\\Sprites\\Enermy\\" ,"ink","stand", 1, 30);

	pData->ppTextureArrays[ 0 ] -> setAnchorPoint(0.5f, 1.0f );

	pData -> ppTextureArrays [ 1 ] = new TextureArray("Resources\\Sprites\\Enermy\\","ink","jump", 1, 30);

	pData->ppTextureArrays[ 1 ] -> setAnchorPoint(0.5f, 1.0f );

	pData ->dir = Direction::createRight();

	pData ->pState = new EnermyInkStandingState(pData);

	pData ->body = RectF( -11.0f, -62.0f, 22.0f, 62.0f);
}

void EnermyInkSprite :: draw( Camera* cam) 
{
	if( pData -> dir.isRight())
		pData->ppTextureArrays[ pData->iCurrentArr ] -> draw(pData -> x, pData -> y , cam);
	else if( pData -> dir.isLeft())
		pData->ppTextureArrays[ pData->iCurrentArr ] -> drawFlipX(pData -> x, pData -> y , cam);
}

void EnermyInkSprite :: update() 
{
	pData ->pState ->onUpdate(); 

}

void EnermyInkSprite :: setPlayerX(int x) {pData ->playerX = x; }
void EnermyInkSprite :: setPlayerY( int y ) { pData ->playerY = y; }