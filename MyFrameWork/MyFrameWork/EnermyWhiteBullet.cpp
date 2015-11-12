#include "EnermyWhiteBullet.h"
#include "BulletMovingState.h"

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

	pData->pState = new BulletMovingState(pData, 2.0f, angle, 0);
}

void EnermyWhiteBullet::draw(Camera* cam)
{
	pData->ppTextureArrays[0]->draw(pData->x, pData->y, cam);
}
void EnermyWhiteBullet::update()
{
	pData->pState->onUpdate();
}
