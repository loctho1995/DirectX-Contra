#include "GunBoss1Bullet.h"
#include "GunBoss1BulletMovingState.h"
#include "GunBoss1BulletExploringState.h"

GunBoss1Bullet :: GunBoss1Bullet(float x, float y)
{
	pData = new SpriteData();
	
	pData -> isHittable = false;

	pData ->ppTextureArrays = new TextureArray*[2];

	pData ->ppTextureArrays[0] = new TextureArray("Resources\\Sprites\\Bullets", "gunboss1bullet","", 1, 60, D3DCOLOR_XRGB(255,255,255));

	pData -> ppTextureArrays[0] ->setAnchorPoint( 0.5f,0.5f );

	pData ->ppTextureArrays[1] = new TextureArray("Resources\\Sprites\\Explosions", "explosion","", 3, 8);

	pData -> ppTextureArrays[1] ->setAnchorPoint( 0.5f,0.5f );


	pData -> x = x;
	
	pData -> y = y;

	pData -> isDesTroyed  = false;

	pData -> body = RectF(- pData ->ppTextureArrays[0] ->getWidth() / 2, -pData ->ppTextureArrays[0] ->getHeight(),pData -> ppTextureArrays[0] ->getWidth() , pData ->ppTextureArrays[0] ->getHeight());

	pData -> dir = Direction :: createLeft();
	
	pData -> pState = new GunBoss1BulletMovingState(pData);
}

void GunBoss1Bullet :: draw(Camera* cam)
{
	pData ->ppTextureArrays[pData -> iCurrentArr] ->draw(pData -> x, pData -> y, cam );
}
void GunBoss1Bullet :: update()
{
	pData ->pState ->onUpdate();
}
void GunBoss1Bullet :: die()
{
	pData -> pState ->onDead();
}


