#include"EnermyScubarSoliderData.h"

EnermyScubarSoliderData::EnermyScubarSoliderData(std::vector < BulletSprite* >& bulletsVector)
	:
	EnermyData(bulletsVector)
{
	this->isHittable = false;
	this->isThrougable = true;

	this->isDesTroyed = false;
	this->HP = 1;
	this->botName = "scubarsolider";
	this->score = 1000;
}

EnermyScubarSoliderData::~EnermyScubarSoliderData()
{

}