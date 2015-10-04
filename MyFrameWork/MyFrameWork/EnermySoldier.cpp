#include "EnermySoldier.h"


EnermySoldier::EnermySoldier(int respawnX, int respawnY)
{
    pData = new EnermySoldierData();

    pData->x = respawnX;
    pData->y = respawnY;
    
    this->initTextureArrays(EnermySoldierData::COUNT);
    this->addTextureArray(EnermySoldierData::RUN, "run", 3, 6); // them 1 state voi animation

    pData->dir = Direction::createLeft();
    pData->body = RectF(-8.5f, -32.0f, 17.0f, 32.0f);
    pData->vx = pData->vy = 0;
    pData->pState = new EnermySoldierRunningState(pData);
}

EnermySoldier::~EnermySoldier()
{

}