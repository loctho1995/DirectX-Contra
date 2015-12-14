#include "EnemyBazokaSprite.h"
#include "EnemyBazokaStandingState.h"
#include "Sound.h"
EnemyBazokaSprite::EnemyBazokaSprite(float respawnX, float respawnY, std::vector<BulletSprite*>& bulletVector)
	:
	EnermySprite(bulletVector)
{
	pData -> x = respawnX;
	pData -> y = respawnY;
	pData -> respawnX = respawnX;
	pData -> respawnY = respawnY;
	pData -> isHittable = true;
	pData -> isThrougable = false;
	pData -> botName = "bazoka";
	pData -> HP = 10;
	pData -> score = 500;
	pData ->dir = Direction::createLeft();
	pData->ppTextureArrays = new TextureArray* [ 3 ];
	pData->ppTextureArrays[0 ] = new TextureArray("Resources\\Sprites\\Enermy" ,"bazoka","stand", 1 , 60);
	pData->ppTextureArrays[0 ] -> setAnchorPoint(0.5f, 1.0f);
	pData->ppTextureArrays[1 ] = new TextureArray("Resources\\Sprites\\Enermy" ,"bazoka","fire", 1 , 60);
	pData->ppTextureArrays[1 ] -> setAnchorPoint(0.5f, 1.0f);
	pData->ppTextureArrays[2 ] = new TextureArray("Resources\\Sprites\\Explosions" ,"explosiontype1","", 3 , 8);
	pData->ppTextureArrays[2 ] -> setAnchorPoint(0.5f, 1.0f);
	pData ->body = RectF( -26.0f / 2, -30.0f, 26.0f, 30.0f);
	pData -> pState = new EnemyBazokaStandingState(pData);
}


void EnemyBazokaSprite:: loadResources()
{
	TextureArray* temp;

	temp = new TextureArray("Resources\\Sprites\\Enermy" ,"bazoka","stand", 1 , 60);

	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Explosions" ,"bazoka","fire", 1 , 60);

	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Explosions" ,"explosiontype1","", 3 , 8);

	delete temp;
}

void EnemyBazokaSprite:: playBeShootedEffect()
{
	Sound::getInstance() -> play("beShooted", false , 1);
}

EnemyBazokaSprite::~EnemyBazokaSprite(void)
{
}
