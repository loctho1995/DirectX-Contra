#include "PlayerMBullet.h"
#include "BulletMovingState.h"

PlayerMBullet :: PlayerMBullet(float x, float y, bool  isBoosting, float angle)
{
	pData = new SpriteData();

	pData ->isDesTroyed = false;
	
	pData ->ppTextureArrays = new TextureArray*[1];

	pData ->ppTextureArrays[0] = new TextureArray("Resources\\Sprites\\Bullets", "mbullet","", 1, 60);

	pData -> ppTextureArrays[0] ->setAnchorPoint( 0.5f,0.5f );

	pData -> x = x;
	
	pData -> y = y;

	pData -> body = RectF(- pData ->ppTextureArrays[0] ->getWidth() / 2, -pData ->ppTextureArrays[0] ->getHeight(),pData -> ppTextureArrays[0] ->getWidth() , pData ->ppTextureArrays[0] ->getHeight());
	
	pData -> pState = new BulletMovingState(pData, 3.0f, angle,0 ) ;
}

void PlayerMBullet :: draw(Camera* cam)
{
	pData ->ppTextureArrays[0] ->draw(pData -> x, pData -> y, cam );
}
void PlayerMBullet :: update()
{
	pData ->pState ->onUpdate();
}
