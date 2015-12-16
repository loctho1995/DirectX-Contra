#include "ObjectCapsuleWeapon.h"
#include "ObjectCapsuleWeaponFlyingState.h"


ObjectCapsuleWeapon::ObjectCapsuleWeapon(int respawnX, int respawnY, int isStage, BulletTypes bulletType)
{
	this->pData = new ObjectCapsuleWeaponData();

	this->pData->x = respawnX;
	this->pData->y = respawnY;

	((ObjectCapsuleWeaponData*)(this->pData))->bulletType = bulletType;
	this->initTextureArrays(ObjectCapsuleWeaponData::COUNT);
	this->addTextureArray(ObjectCapsuleWeaponData::FLY, "", 1, 5);
	this->pData->dir = Direction::createRight();
	this->pData->appearDir = Direction::createLeft();
	this->pData->body = RectF(0.0f, 0.0f, 24.0f, 15.0f);
	this->pData->HP = 1;
	this->pData->pState = new ObjectCapsuleWeaponFlyingState(this->pData, isStage);

	switch (bulletType)
	{
	case M:
		this->pData->ppTextureArrays[ObjectCapsuleWeaponData::DROP] = new TextureArray("Resources\\Sprites", "bulletimages", "m", 1, 10);
		break;

	case F:
		this->pData->ppTextureArrays[ObjectCapsuleWeaponData::DROP] = new TextureArray("Resources\\Sprites", "bulletimages", "f", 1, 10);
		break;

	case S:
		this->pData->ppTextureArrays[ObjectCapsuleWeaponData::DROP] = new TextureArray("Resources\\Sprites", "bulletimages", "s", 1, 10);
		break;

	case B:
		this->pData->ppTextureArrays[ObjectCapsuleWeaponData::DROP] = new TextureArray("Resources\\Sprites", "bulletimages", "b", 1, 10);
		break;

	case L:
		this->pData->ppTextureArrays[ObjectCapsuleWeaponData::DROP] = new TextureArray("Resources\\Sprites", "bulletimages", "l", 1, 10);
		break;

	case R:
		this->pData->ppTextureArrays[ObjectCapsuleWeaponData::DROP] = new TextureArray("Resources\\Sprites", "bulletimages", "r", 1, 10);
		break;

	case N:
		this->pData->ppTextureArrays[ObjectCapsuleWeaponData::DROP] = new TextureArray("Resources\\Sprites", "bulletimages", "n", 1, 10);
		break;

	case D:
		this->pData->ppTextureArrays[ObjectCapsuleWeaponData::DROP] = new TextureArray("Resources\\Sprites", "bulletimages", "d", 1, 10);
		break;
	default:
		break;
	}
	this->pData->ppTextureArrays[ObjectCapsuleWeaponData::DROP]->setAnchorPoint(0.5f, 0.5f);
}


ObjectCapsuleWeapon::~ObjectCapsuleWeapon()
{
}

void ObjectCapsuleWeapon::draw(Camera* cam)
{
	if (pData->dir.isRight())
		pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
	else if (pData->dir.isLeft())
		pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
}
void ObjectCapsuleWeapon::update()
{
	ObjectSprite::update();
}

bool ObjectCapsuleWeapon::isDesTroyed()
{
	return pData->isDesTroyed;
}

BulletTypes ObjectCapsuleWeapon::getBulletType()
{
	return ((ObjectCapsuleWeaponData*)(this->pData))->bulletType;
}

void ObjectCapsuleWeapon::onCameraCollision(RectF rect)
{
	this->pData->pState->onCameraCollision(rect);
}