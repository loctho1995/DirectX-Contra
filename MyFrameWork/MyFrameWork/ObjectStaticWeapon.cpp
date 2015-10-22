#include "ObjectStaticWeapon.h"


ObjectStaticWeapon::ObjectStaticWeapon(float x, float y)
{
    this->pData = new ObjectStaticWeaponData();
    this->pData->x = x;
    this->pData->y = y;
    this->pData->dir = Direction::createRight();
    this->pData->vx = pData->vy = 0;
    
    this->initTextureArrays(ObjectStaticWeaponData::COUNT);
    this->addTextureArray(ObjectStaticWeaponData::OPENED, "open", 3, 8);
    this->addTextureArray(ObjectStaticWeaponData::CLOSED, "close", 1, 4);
    this->addTextureArray(ObjectStaticWeaponData::PREAPRING, "preparing", 3, 2);
    //this->addTextureArray(ObjectStaticWeaponData::OUTX, "out", 3, 2);
    this->pData->ppTextureArrays[ObjectStaticWeaponData::OUTX] = new TextureArray("Resources\\Sprites", "bulletimages", "m", 1, 10);
    this->pData->body = RectF(0, 0, 32, 32);
    this->pData->pState = new ObjectStaticWeaponCloseState(this->pData);
    //this->pData->pState = new ObjectStaticWeaponOutState(this->pData);
}


ObjectStaticWeapon::~ObjectStaticWeapon()
{
}

void ObjectStaticWeapon::beShooted(int damage)
{
    this->pData->pState = new ObjectStaticWeaponOutState(this->pData);
}