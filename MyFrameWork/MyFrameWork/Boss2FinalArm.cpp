#include "Boss2FinalArm.h"


Boss2FinalArm::Boss2FinalArm(float x, float y, std::vector<BulletSprite*>& bulletSprites, Boss2FinalData::ArmSide armSide)
{
    this->pData = new Boss2FinalData(bulletSprites);
    this->pData->botName = "boss2arm";
    this->pData->HP = 10;
    this->pData->score = 2000;
    this->pData->x = x;
    this->pData->y = y;
    this->pData->body = RectF(-8, -8, 16, 16);    
    this->pData->isDesTroyed = false;
    this->pData->isThrougable = false;
    this->pData->iCurrentArr = 0;

    explosion = new Boss2FinalExplosionSprite(0, 0);

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
    delete explosion;
}

RectF Boss2FinalArm::getBody()
{
    return ((Boss2FinalData*)pData)->joints[4]->getBody();
}

void Boss2FinalArm::die()
{
    explosion->setPosition(((Boss2FinalData*)pData)->joints[4]->getPosition());

    Sound::getInstance()->play("boss2finalhanddisappear.wav", false, 1);
}

void Boss2FinalArm::update()
{
    if (pData->isDead)
    {
        explosion->update();

        if (explosion->isFinishAnimation())
        {
            if (((Boss2FinalData*)pData)->armSide == Boss2FinalData::ArmSide::LEFT)
            {
                Boss2Final::getInstance()->setLeftArmState(true);
            }
            else
            {
                Boss2Final::getInstance()->setRightArmState(true);
            }
            
            this->pData->isDesTroyed = true;
            return;
        }
    }
    else
    {
        this->pData->pState->onUpdate();
    }
}

void Boss2FinalArm::draw(Camera *cam)
{
    if (pData->isDead)
    {
        explosion->draw(cam);
    }
    else
    {
        for (size_t i = 0; i < 5; i++)
        {
            ((Boss2FinalData*)pData)->joints[i]->draw(cam);
        }
    }
}