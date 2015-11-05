#include"EnermyGunRotatingData.h"

EnermyGunRotatingData::EnermyGunRotatingData()
{
	this->botName = "gunrotating";
	this->isHittable = false;
	this->isThrougable = true;
	this->isDesTroyed = false;
	this->HP = 10;
	this->appearDir = Direction::createRight();
}
EnermyGunRotatingData::~EnermyGunRotatingData()
{

}