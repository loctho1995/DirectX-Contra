#include "LBullet.h"
#include "BulletMovingState.h"

LBullet :: LBullet(float x, float y, float speed, float angle)
{
	pData = new SpriteData();

	pData ->isDesTroyed = false;
	
	pData ->ppTextureArrays = new TextureArray*[1];

	pData ->ppTextureArrays[0] = new TextureArray("Resources\\Sprites\\Bullets", "lbullet","", 1, 4);

	pData -> ppTextureArrays[0] ->setAnchorPoint( 0.5f,0.5f );

	pData -> x = x;
	
	pData -> y = y;

	pData -> body = RectF(- pData ->ppTextureArrays[0] ->getWidth() / 2, -pData ->ppTextureArrays[0] ->getHeight(),pData -> ppTextureArrays[0] ->getWidth() , pData ->ppTextureArrays[0] ->getHeight());
	
	pData -> pState = new BulletMovingState(pData, speed,  angle, 0 );
}

void LBullet :: draw(Camera* cam)
{
	pData ->ppTextureArrays[0] ->draw(pData -> x, pData -> y, cam );
}
void LBullet :: update()
{
	pData ->pState ->onUpdate();
}
