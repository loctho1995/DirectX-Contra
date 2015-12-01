#include "ObjectStaticWeapon.h"


ObjectStaticWeapon::ObjectStaticWeapon(float x, float y, BulletTypes bulletType)
{
    pData = new ObjectStaticWeaponData();
    pData->x = x;
    pData->y = y;
    pData->dir = Direction::createRight();
    pData->vx = pData->vy = 0;

    ((ObjectStaticWeaponData*)(this->pData))->bulletType = bulletType;
    
    this->initTextureArrays(ObjectStaticWeaponData::COUNT);
    this->addTextureArray(ObjectStaticWeaponData::OPENED, "open", 3, 8);
    this->addTextureArray(ObjectStaticWeaponData::CLOSED, "close", 1, 4);
    this->addTextureArray(ObjectStaticWeaponData::PREAPRING, "preparing", 3, 2);
    //this->addTextureArray(ObjectStaticWeaponData::OUTX, "out", 3, 2);

    switch (bulletType)
    {
    case M:
        this->pData->ppTextureArrays[ObjectStaticWeaponData::OUTX] = new TextureArray("Resources\\Sprites", "bulletimages", "m", 1, 10);
        break;

    case F:
        this->pData->ppTextureArrays[ObjectStaticWeaponData::OUTX] = new TextureArray("Resources\\Sprites", "bulletimages", "f", 1, 10);
        break;

    case S:
        this->pData->ppTextureArrays[ObjectStaticWeaponData::OUTX] = new TextureArray("Resources\\Sprites", "bulletimages", "s", 1, 10);
        break;

    case B:
        this->pData->ppTextureArrays[ObjectStaticWeaponData::OUTX] = new TextureArray("Resources\\Sprites", "bulletimages", "b", 1, 10);
        break;

    case L:
        this->pData->ppTextureArrays[ObjectStaticWeaponData::OUTX] = new TextureArray("Resources\\Sprites", "bulletimages", "l", 1, 10);
        break;

    case R:
        this->pData->ppTextureArrays[ObjectStaticWeaponData::OUTX] = new TextureArray("Resources\\Sprites", "bulletimages", "r", 1, 10);
        break;

    case N:
        this->pData->ppTextureArrays[ObjectStaticWeaponData::OUTX] = new TextureArray("Resources\\Sprites", "bulletimages", "n", 1, 10);
        break;

    default:
        break;
    }

    

    this->pData->ppTextureArrays[ObjectStaticWeaponData::CLOSED]->setAnchorPoint(0, 0);
    this->pData->ppTextureArrays[ObjectStaticWeaponData::OPENED]->setAnchorPoint(0, 0);
    this->pData->ppTextureArrays[ObjectStaticWeaponData::PREAPRING]->setAnchorPoint(0, 0);
    this->pData->ppTextureArrays[ObjectStaticWeaponData::OUTX]->setAnchorPoint(0, 0);

    this->pData->body = RectF(0, 0, 32, 32);
    this->pData->pState = new ObjectStaticWeaponCloseState(this->pData);
    //this->pData->pState = new ObjectStaticWeaponOutState(this->pData);
}


ObjectStaticWeapon::~ObjectStaticWeapon()
{
     
}

void ObjectStaticWeapon::beShooted(int damage)
{
    if (this->pData->iCurrentArr == ObjectStaticWeaponData::OPENED)
        this->pData->pState = new ObjectStaticWeaponOutState(this->pData);
}

BulletTypes ObjectStaticWeapon::getBulletType()
{
    return ((ObjectStaticWeaponData*)(this->pData))->bulletType;
}

void ObjectStaticWeapon::onCameraCollision(RectF rect)
{
    this->pData->pState->onCameraCollision(rect);
}

void ObjectStaticWeapon::die()
{
	pData ->isDesTroyed = true;
}

void ObjectStaticWeapon::loadResources()
{
    TextureArray *temp = new TextureArray("Resources\\Sprites", "bulletimages", "m", 1, 10);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "bulletimages", "f", 1, 10);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "bulletimages", "s", 1, 10);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "bulletimages", "r", 1, 10);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "bulletimages", "b", 1, 10);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "bulletimages", "l", 1, 10);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "bulletimages", "n", 1, 10);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "staticweapon", "open", 1, 10);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "staticweapon", "open", 1, 10);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "staticweapon", "preparing", 1, 10);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "staticweapon", "close", 1, 10);
    delete temp;
}