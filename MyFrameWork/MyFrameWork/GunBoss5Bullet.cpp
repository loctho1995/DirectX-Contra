#include "GunBoss5Bullet.h"

GunBoss5Bullet::GunBoss5Bullet(float x, float y)
{
	pData = new SpriteData();
	pData->x = x;
	pData->y = y;

	pData->ppTextureArrays = new TextureArray*[2];
	//bullet
	pData->ppTextureArrays[0] = new TextureArray("Resources\\Sprites\\finalboss5", "bullet", "", 1, 10);
	pData->ppTextureArrays[0]->setAnchorPoint(0.5f, 0.5f);
	//die
	pData->ppTextureArrays[1] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 6);
	pData->ppTextureArrays[1]->setAnchorPoint(0.5f, 0.5f);

	pData->body = RectF(-5.5f,-5.5f,11.0f,11.0f);
	pData->pState = new GunBoss5BulletMovingState(pData);
	pData->isDesTroyed = false;
	pData->isHittable = true;
}


GunBoss5Bullet::~GunBoss5Bullet()
{
}

void GunBoss5Bullet::draw(Camera* cam)
{
	pData->ppTextureArrays[this->pData->iCurrentArr]->draw(pData->x, pData->y, cam);
}
void GunBoss5Bullet::update()
{
	pData->pState->onUpdate();
}

void GunBoss5Bullet::die()
{
	pData->pState->onDead();
}