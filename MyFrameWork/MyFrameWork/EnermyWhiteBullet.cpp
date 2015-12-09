#include "EnermyWhiteBullet.h"
#include "BulletMovingState.h"

EnermyWhiteBullet::EnermyWhiteBullet(float x, float y, bool  isBoosting, float angle, int kindBullet)
{
	pData = new SpriteData();

	pData -> isHittable = false;

	pData->isDesTroyed = false;

	this->kindBullet = kindBullet;

	pData->ppTextureArrays = new TextureArray*[2];

	pData->ppTextureArrays[0] = new TextureArray("Resources\\Sprites\\Bullets", "wbullet", "", 1, 10);

	pData->ppTextureArrays[0]->setAnchorPoint(0.5f, 0.5f);

	pData->ppTextureArrays[1] = new TextureArray("Resources\\Sprites\\Bullets", "tankbullet", "", 1, 10);

	pData->ppTextureArrays[1]->setAnchorPoint(0.5f, 0.5f);

	pData->x = x;

	pData->y = y;

	pData->body = RectF(-pData->ppTextureArrays[kindBullet]->getWidth() / 2, -pData->ppTextureArrays[0]->getHeight(), pData->ppTextureArrays[0]->getWidth(), pData->ppTextureArrays[0]->getHeight());

	pData->pState = new BulletMovingState(pData, 1.0f, angle, 0);
}

void EnermyWhiteBullet::draw(Camera* cam)
{
	pData->ppTextureArrays[kindBullet]->draw(pData->x, pData->y, cam);
}
void EnermyWhiteBullet::update()
{
	pData->pState->onUpdate();
}
