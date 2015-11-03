#include "EnermySoldier.h"


EnermySoldier::EnermySoldier(float x, float y)
{
    pData = new EnermySoldierData();

    pData->x = x;
    pData->y = y;
    
    this->initTextureArrays(EnermySoldierData::COUNT);
    this->addTextureArray(EnermySoldierData::RUN, "run", 3, 6); // them 1 state voi animation
    this->addTextureArray(EnermySoldierData::JUMP, "jump", 1, 60);
    this->addTextureArray(EnermySoldierData::DIE, "jump", 1, 60);
    this->addTextureArray(EnermySoldierData::FALL, "jump", 1, 60);
    this->pData->ppTextureArrays[EnermySoldierData::DESTROY] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "type1", 3, 10);
    this->pData->ppTextureArrays[EnermySoldierData::DESTROY]->setAnchorPoint(0.5f, 0.5f);

    pData->dir = Direction::createLeft();
    pData->body = RectF(-9.0f, -33.0f, 18.0f, 33.0f);
    pData->vx = pData->vy = 0;

    pData->pState = new EnermySoldierRunningState(pData);
    //pData->pState = new EnermySoldierJumpingState(pData);
    //pData->pState = new EnermySoldierDestroyState(pData);
    //pData->pState = new EnermySoldierDieState(pData);
}

EnermySoldier::~EnermySoldier()
{

}

void EnermySoldier::setSupportCollisionRect(CollisionRectF rect)
{
    this->pData->cSupportRect = rect;
}

void EnermySoldier::die()
{
    this->pData->pState = new EnermySoldierDieState(this->pData);
}


void EnermySoldier::onCameraCollision(RectF cameraRect)
{
    if (this->pData->x - (cameraRect.x + cameraRect.width) >= -SOLDIER_RANGE_TO_TURN)
    {
        if (this->pData->dir.isRight())
            this->pData->dir = Direction::createLeft();
    }
}