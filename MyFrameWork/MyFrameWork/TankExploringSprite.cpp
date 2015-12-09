#include"TankExploringSprite.h"
#include"TankExploringState.h"

TankExploringSprite::TankExploringSprite(int x, int y)
{
	pData = new SpriteData();

	pData->ppTextureArrays = new TextureArray*[1];

	pData->ppTextureArrays[0] = new  TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 8);

	pData->ppTextureArrays[0]->setAnchorPoint(0.5f, 0.5f);

	pData->x = x;

	pData->y = y;


	pData->isDesTroyed = false;

	pData->body = RectF(-pData->ppTextureArrays[0]->getWidth() / 2, -pData->ppTextureArrays[0]->getHeight(), pData->ppTextureArrays[0]->getWidth(), pData->ppTextureArrays[0]->getHeight());

	pData->dir = Direction::createLeft();

	pData->pState = new TankExploringState(pData);
}

TankExploringSprite::~TankExploringSprite()
{

}
void TankExploringSprite::draw(Camera *cam)
{
	pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
}
void TankExploringSprite::update()
{
	pData->pState->onUpdate();
}
void TankExploringSprite::die()
{
	pData->pState->onDead();
}