#include "EnermySoldierRun.h"


EnermySoldierRun::EnermySoldierRun(int respawnX, int respawnY)
{
    pData = new EnermySoldierRunData("runningsoldier");

    pData->x = respawnX;
    pData->y = respawnY;
    
    this->initTextureArrays(EnermySoldierRunData::COUNT);
    this->addTextureArray(EnermySoldierRunData::RUN, "run", 3, 6); // them 1 state voi animation

    pData->dir = Direction::createLeft();
    pData->body = RectF(-8.5f, -32.0f, 17.0f, 32.0f);
    pData->vx = pData->vy = 0;
    pData->pState = new EnermySoldierRunRunningState(pData);
}

EnermySoldierRun::~EnermySoldierRun()
{

}