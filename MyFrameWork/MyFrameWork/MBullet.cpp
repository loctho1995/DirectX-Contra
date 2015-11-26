#include "MBullet.h"
#include "BulletMovingState.h"

MBullet :: MBullet(float x, float y, float speed, float angle)
{
	pData = new SpriteData();

	pData -> isHittable = false;


	pData ->isDesTroyed = false;
	
	pData ->ppTextureArrays = new TextureArray*[1];

	pData ->ppTextureArrays[0] = new TextureArray("Resources\\Sprites\\Bullets", "mbullet","", 1, 60);

	pData -> ppTextureArrays[0] ->setAnchorPoint( 0.5f,0.5f );

	pData -> x = x;
	
	pData -> y = y;

	pData -> body = RectF(- pData ->ppTextureArrays[0] ->getWidth() / 2, -pData ->ppTextureArrays[0] ->getHeight(),pData -> ppTextureArrays[0] ->getWidth() , pData ->ppTextureArrays[0] ->getHeight());
	
	pData -> pState = new BulletMovingState(pData, speed, angle,0 ) ;
}

void MBullet :: draw(Camera* cam)
{
	pData ->ppTextureArrays[0] ->draw(pData -> x, pData -> y, cam );
}
void MBullet :: update()
{
	pData ->pState ->onUpdate();
}
