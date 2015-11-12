#include "LBullet.h"
#include "BulletMovingState.h"

LBullet :: LBullet(float x, float y, float speed, float angle)
{
	pData = new SpriteData();

	pData ->isDesTroyed = false;
	
	pData ->ppTextureArrays = new TextureArray*[4];

	pData ->ppTextureArrays[0] = new TextureArray("Resources\\Sprites\\Bullets", "lbullet","horizontal", 1, 60);

	pData -> ppTextureArrays[0] ->setAnchorPoint( 0.5f,0.5f );

	pData ->ppTextureArrays[1] = new TextureArray("Resources\\Sprites\\Bullets", "lbullet","vertical", 1, 60);

	pData -> ppTextureArrays[1] ->setAnchorPoint( 0.5f,0.5f );

	pData ->ppTextureArrays[2] = new TextureArray("Resources\\Sprites\\Bullets", "lbullet","-45oblique", 1, 60);

	pData -> ppTextureArrays[2] ->setAnchorPoint( 0.5f,0.5f );

	pData ->ppTextureArrays[3] = new TextureArray("Resources\\Sprites\\Bullets", "lbullet","45oblique", 1, 60);

	pData -> ppTextureArrays[3] ->setAnchorPoint( 0.5f,0.5f );

	pData -> x = x;
	
	pData -> y = y;

	
	int index;
	if( angle == 0.0f || angle == (float)M_PI || angle == -(float)M_PI )
	{
		index = 0;
	}
	else if( angle == (float)M_PI_2 || angle == -(float)M_PI_2)
	{
		index = 1;
	}
	else if( angle == (float)(-M_PI_4 - M_PI_2) || angle == (float)M_PI_4 )
	{
		index = 3;
	}
	else
	{
		index = 2;
	}
	
	pData -> body = RectF(- pData ->ppTextureArrays[index] ->getWidth() / 2, -pData ->ppTextureArrays[index] ->getHeight(),pData -> ppTextureArrays[index] ->getWidth() , pData ->ppTextureArrays[index] ->getHeight());

	pData -> pState = new BulletMovingState(pData, speed,  angle, index );
}

void LBullet :: draw(Camera* cam)
{
	pData ->ppTextureArrays[pData -> iCurrentArr] ->draw(pData -> x, pData -> y, cam );
}
void LBullet :: update()
{
	pData ->pState ->onUpdate();
}
