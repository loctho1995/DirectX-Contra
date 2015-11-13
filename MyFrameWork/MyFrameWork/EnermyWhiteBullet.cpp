#include "EnermyWhiteBullet.h"
#include "BulletMovingState.h"

bool isShoot = false;
EnermyWhiteBullet::EnermyWhiteBullet(float x, float y, bool  isBoosting, float angle)
{
	pData = new SpriteData();

	pData->isDesTroyed = false;

	pData->ppTextureArrays = new TextureArray*[1];

	pData->ppTextureArrays[0] = new TextureArray("Resources\\Sprites\\Bullets", "wbullet", "", 1, 10);

	pData->ppTextureArrays[0]->setAnchorPoint(0.5f, 0.5f);

	pData->x = x;

	pData->y = y;

	pData->body = RectF(-pData->ppTextureArrays[0]->getWidth() / 2, -pData->ppTextureArrays[0]->getHeight(), pData->ppTextureArrays[0]->getWidth(), pData->ppTextureArrays[0]->getHeight());

	pData->pState = new BulletMovingState(pData, 1.0f, angle, 0);
	isShoot = isBoosting;
}

void EnermyWhiteBullet::draw(Camera* cam)
{
	if (isShoot == true)
	pData->ppTextureArrays[0]->draw(pData->x, pData->y, cam);
}
void EnermyWhiteBullet::update()
{
	if (isShoot == true)
	pData->pState->onUpdate();
}
