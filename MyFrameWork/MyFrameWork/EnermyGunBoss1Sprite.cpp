#include "EnermyGunBoss1Sprite.h"
#include "EnermyGunBoss1StandingState.h"

EnermyGunBoss1Sprite :: EnermyGunBoss1Sprite( int respawnX, int respawnY, std::vector < BulletSprite*>& bulletSpriteVector)
	:
	EnermySprite(bulletSpriteVector)
{

	pData -> botName = "gunboss1";

	pData->x  = respawnX;

	pData->y  = respawnY;

	pData->ppTextureArrays = new TextureArray* [ 3 ];

	pData->ppTextureArrays[0 ] = new TextureArray("Resources\\Sprites\\Enermy" ,"gunboss1","stand", 1, 60);

	pData->ppTextureArrays[ 0 ] -> setAnchorPoint(0.5f, 1.0f );

	pData -> ppTextureArrays [ 1 ] = new TextureArray("Resources\\Sprites\\Enermy","gunboss1","fire", 1, 60);

	pData->ppTextureArrays[ 1 ] -> setAnchorPoint(0.5f, 1.0f );

	pData ->ppTextureArrays[2] = new TextureArray("Resources\\Sprites\\Explosions", "explosion","", 3, 8);

	pData->ppTextureArrays[ 2 ] -> setAnchorPoint(0.5f, 1.0f );

	pData ->dir = Direction::createLeft();

	pData ->pState = new EnermyGunBoss1StandingState(pData);

	pData -> isThrougable = false;

	pData -> HP = 16;

	pData -> score	= 1000;

	pData ->body = RectF( -6.0f, -6.0f, 12.0f, 8.0f);
}
void EnermyGunBoss1Sprite :: draw( Camera* cam) 
{
	if( pData -> dir.isRight())
		pData->ppTextureArrays[ pData->iCurrentArr ] -> drawFlipX(pData -> x, pData -> y , cam);
	else if( pData -> dir.isLeft())
		pData->ppTextureArrays[ pData->iCurrentArr ] -> draw(pData -> x, pData -> y , cam);
}
void EnermyGunBoss1Sprite :: update() 
{
	pData ->pState ->onUpdate();
}

void EnermyGunBoss1Sprite :: loadResources()
{
	// loadSprite
	TextureArray* temp = new TextureArray("Resources\\Sprites\\Enermy" ,"gunboss1","stand", 1, 60);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\Enermy","gunboss1","fire", 1, 60);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion","", 6, 8);
	delete temp;

	// loadBullet
	temp = new TextureArray("Resources\\Sprites\\Bullets", "gunboss1bullet","", 1, 60, D3DCOLOR_XRGB(255,255,255));
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion","", 6, 8);
	delete temp;
}

void EnermyGunBoss1Sprite :: playBeShootedEffect()
{
	Sound::getInstance() -> play("beShooted", false, 1);
}