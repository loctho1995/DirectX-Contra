#include "EnermyGunBoss1Sprite.h"
#include "EnermyGunBoss1StandingState.h"

EnermyGunBoss1Sprite :: EnermyGunBoss1Sprite( int respawnX, int respawnY)
{
	pData = new EnermyData();

	pData -> botName = "gunboss1";

	pData->x  = respawnX;

	pData->y  = respawnY;
	
	pData -> isThrougable = false;

	pData->ppTextureArrays = new TextureArray* [ 3 ];

	pData->ppTextureArrays[0 ] = new TextureArray("Resources\\Sprites\\Enermy" ,"gunboss1","stand", 1, 60);

	pData->ppTextureArrays[ 0 ] -> setAnchorPoint(0.5f, 1.0f );

	pData -> ppTextureArrays [ 1 ] = new TextureArray("Resources\\Sprites\\Enermy","gunboss1","fire", 1, 60);

	pData->ppTextureArrays[ 1 ] -> setAnchorPoint(0.5f, 1.0f );

	pData ->ppTextureArrays[2] = new TextureArray("Resources\\Sprites\\Explosions", "explosion","", 6, 8);

	pData->ppTextureArrays[ 2 ] -> setAnchorPoint(0.5f, 1.0f );

	pData ->dir = Direction::createLeft();

	pData ->pState = new EnermyGunBoss1StandingState(pData);

	pData -> HP = 1;

	pData ->body = RectF( -6.0f, -6.0f, 12.0f, 8.0f);
}
void EnermyGunBoss1Sprite :: draw( Camera* cam) 
{
	if( pData -> dir.isRight())
		pData->ppTextureArrays[ pData->iCurrentArr ] -> draw(pData -> x, pData -> y , cam);
	else if( pData -> dir.isLeft())
		pData->ppTextureArrays[ pData->iCurrentArr ] -> drawFlipX(pData -> x, pData -> y , cam);

	for (int i = 0; i < pData->Bullets.size(); i++)
	{
		pData-> Bullets[i] ->draw(cam);
	}
}
void EnermyGunBoss1Sprite :: update() 
{
	pData ->pState ->onUpdate();

	for (int i = 0; i < pData->Bullets.size(); i++)
	{
		Sprite* temp = pData ->Bullets[i];
		if( temp -> isDesTroyed	() )
		{
			pData ->Bullets.erase( pData ->Bullets.begin() + i);
			delete temp;
		}
		else
		{
			temp -> update();
		}
		
		
	}


}