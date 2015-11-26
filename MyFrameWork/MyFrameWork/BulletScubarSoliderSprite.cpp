#include"BulletScubarSoliderSprite.h"
#include"BulletScubarSoliderMovingState.h"

BulletScubarSoliderSprite::BulletScubarSoliderSprite(float x, float y, int index1, float vx, int kindEnemy)
 {
	 pData = new SpriteData();

	 pData->ppTextureArrays = new TextureArray*[3];

	 pData->ppTextureArrays[0] = new TextureArray("Resources\\Sprites\\Bullets", "gunboss1bullet", "", 1, 60);

	 pData->ppTextureArrays[0]->setAnchorPoint(0.5f, 0.5f);

	 pData->ppTextureArrays[1] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 8);

	 pData->ppTextureArrays[1]->setAnchorPoint(0.5f, 0.5f);

	 pData->ppTextureArrays[2] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "type1", 3, 8);

	 pData->ppTextureArrays[2]->setAnchorPoint(0.5f, 0.5f);

	 pData->x = x;

	 pData->y = y;


	 pData->isDesTroyed = false;

	 pData->body = RectF(-pData->ppTextureArrays[0]->getWidth() / 2, -pData->ppTextureArrays[0]->getHeight(), pData->ppTextureArrays[0]->getWidth(), pData->ppTextureArrays[0]->getHeight());

	 pData->dir = Direction::createLeft();

	 pData->pState = new BulletScubarSoliderMovingState(pData, vx, index1, kindEnemy);
}

BulletScubarSoliderSprite::~BulletScubarSoliderSprite()
{
}

void BulletScubarSoliderSprite::draw(Camera *cam)
{
	pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
}

void BulletScubarSoliderSprite::update()
{
	pData->pState->onUpdate();
}

void BulletScubarSoliderSprite::die()
{
	pData->pState->onDead();
}
