#include "Boss2FinalArm.h"


Boss2FinalArm::Boss2FinalArm(float x, float y, std::vector<BulletSprite*>& bulletSprites, Boss2FinalData::ArmSide armSide)
{
    this->pData = new Boss2FinalData(bulletSprites);
    this->pData->botName = "boss2finaldata";
    this->pData->x = x;
    this->pData->y = y;
    this->pData->body = RectF(-8, -8, 16, 16);    
    this->pData->isDesTroyed = false;

    ((Boss2FinalData*)this->pData)->armSide = armSide;
    
    for (size_t i = 0; i < 4; i++)
    {
        ((Boss2FinalData*)pData)->joints[i] = new Boss2FinalJoint(x, y);
    }

    ((Boss2FinalData*)pData)->joints[4] = new Boss2FinalHand(x, y);

    this->pData->pState = new Boss2FinalArmStartState(this->pData);
}


Boss2FinalArm::~Boss2FinalArm()
{

}

//void Boss2FinalArm::setPlayerX(float x)
//{
//    ((Boss2FinalData*)pData)->playerX = x;
//}
//
//void Boss2FinalArm::setPlayerY(float y)
//{
//    ((Boss2FinalData*)pData)->playerY = y;
//}

RectF Boss2FinalArm::getBody()
{
    return ((Boss2FinalData*)pData)->joints[4]->getBody();
}

void Boss2FinalArm::update()
{
    this->pData->pState->onUpdate();
}

void Boss2FinalArm::draw(Camera *cam)
{
    for (size_t i = 0; i < 5; i++)
    {
        ((Boss2FinalData*)pData)->joints[i]->draw(cam);
    }
}