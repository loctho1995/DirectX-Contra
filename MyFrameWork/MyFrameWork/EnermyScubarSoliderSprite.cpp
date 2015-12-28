#include"EnermyScubarSoliderSprite.h"
#include"BulletScubarSoliderSprite.h"
#include"EnermyScubarSoliderShootState.h"
#include"EnermyScubarSoliderData.h"
#include"EnermyScubarSoliderHidingState.h"
#include"Sound.h"



EnermyScubarSoliderSprite::EnermyScubarSoliderSprite(int respawnX, int respawnY,int kind, std::vector < BulletSprite*>& bulletSpriteVector)
	:EnermySprite(bulletSpriteVector)
{
	pData = new EnermyScubarSoliderData(bulletSpriteVector);

	pData->x = respawnX;
	pData->y = respawnY;

	pData->stage = kind; // kind == 1, scubar vi tri 1, 3, kind == 2 scubar vi tri 2

	pData->ppTextureArrays = new TextureArray*[2];

	pData->ppTextureArrays[0] = new TextureArray("Resources\\Sprites", "scubarsolider", "hide", 1, 6);
	pData->ppTextureArrays[0]->setAnchorPoint(0.5f, 0.5f);

	pData->ppTextureArrays[1] = new TextureArray("Resources\\Sprites", "scubarsolider", "shoot", 1, 6);
	pData->ppTextureArrays[1]->setAnchorPoint(0.5f, 0.5f);

	pData->ppTextureArrays[2] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 16);
	pData->ppTextureArrays[2]->setAnchorPoint(0.5f, 0.5f);

	pData->dir = Direction::createRight();

	pData->body = RectF(-20.0f / 2, -18.0f, 20.0f, 18.0f);

	pData->pState = new EnermyScubarSoliderHidingState(pData);
}

EnermyScubarSoliderSprite::~EnermyScubarSoliderSprite()
{

}

void EnermyScubarSoliderSprite::loadResources()
{

	TextureArray* temp = new TextureArray("Resources\\Sprites", "scubarsolider", "hide", 1, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites", "scubarsolider", "shoot", 1, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Bullets", "gunboss1bullet", "", 1, 60);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 6, 8);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "type1", 6, 8);
	delete temp;
}
void EnermyScubarSoliderSprite::draw(Camera* cam)
{
	if (pData->dir.isRight())
		pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
	else
		if (pData->dir.isLeft())
			pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
}

void EnermyScubarSoliderSprite::update()
{
	pData->pState->onUpdate();
}

void EnermyScubarSoliderSprite::playBeShootedEffect()
{
	Sound::getInstance()->play("beShooted", false, 1);
}