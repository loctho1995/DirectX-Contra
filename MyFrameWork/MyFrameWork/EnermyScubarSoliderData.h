#pragma once
#include"EnermyData.h"

class EnermyScubarSoliderData :public EnermyData
{
public:
	EnermyScubarSoliderData(std::vector < BulletSprite* >& bulletsVector = std::vector <BulletSprite* >());
	~EnermyScubarSoliderData();
};