#include "RockMansBullet.h"
#include "BulletMovingState.h"

RockMansBullet :: RockMansBullet(float x, float y, Direction dir)
{
	pData = new SpriteData();
	
	pData ->ppTextureArrays = new TextureArray*[1];

	pData ->ppTextureArrays[0] = new TextureArray("Resources\\Sprites\\RockMan\\Original\\", "bullet","", 1, 60);

	pData -> ppTextureArrays[0] ->setAnchorPoint( 0.5f, 0.5f );

	pData -> x = x;
	
	pData -> y = y;

	pData -> dir = dir;

	pData -> body = RectF(- pData ->ppTextureArrays[0] ->getWidth() / 2, -pData ->ppTextureArrays[0] ->getHeight(),pData -> ppTextureArrays[0] ->getWidth() , pData ->ppTextureArrays[0] ->getHeight());
	
	pData -> pState = new BulletMovingState(pData);
}

void RockMansBullet :: draw(Camera* cam)
{
	pData ->ppTextureArrays[0] ->draw(pData -> x, pData -> y, cam );
}

void RockMansBullet :: update()
{
	pData ->pState ->onUpdate();
}
