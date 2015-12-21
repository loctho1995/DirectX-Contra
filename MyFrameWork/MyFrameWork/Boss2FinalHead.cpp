#include "Boss2FinalHead.h"


Boss2FinalHead::Boss2FinalHead(float x, float y, std::vector<BulletSprite*>& bulletSprite)
{
    this->pData = new Boss2FinalData(bulletSprite);
    this->pData->botName = "finalboss2head";
    this->pData->HP = 12;
    this->pData->score = 10000;
    this->pData->x = x;
    this->pData->y = y - 145;
    this->pData->isHittable = false;
    this->pData->body = RectF(-22.5f, 0, 55, 55);
    this->pData->iCurrentArr = 0;
    this->pData->ppTextureArrays = new TextureArray * [Boss2FinalData::ArrayIndex::COUNT];
    this->pData->ppTextureArrays[Boss2FinalData::ArrayIndex::SHUT] = new TextureArray("Resources\\Sprites", "boss2final", "headshut", 3, 15);
    this->pData->ppTextureArrays[Boss2FinalData::ArrayIndex::OPEN] = new TextureArray("Resources\\Sprites", "boss2final", "head", 5, 25);
    this->pData->ppTextureArrays[Boss2FinalData::ArrayIndex::SHUT]->setAnchorPoint(0.5f, 0.0f);
    this->pData->ppTextureArrays[Boss2FinalData::ArrayIndex::OPEN]->setAnchorPoint(0.5f, 0.0f);
    this->pData->pState = new Boss2FinalHeadShuttingState(this->pData);

    explosion = new Boss2FinalExplosionSprite(0, 0);
    bodySprite = new Boss2FinalBody(128, 146);
}

void Boss2FinalHead::onCameraCollision(RectF rect)
{

}

Boss2FinalHead::~Boss2FinalHead()
{
    delete explosion;
}

void Boss2FinalHead::die()
{
    explosion->setPosition(pData->x, pData->y);

    Sound::getInstance()->play("boss2finaldestroy.wav", false, 1);
}

void Boss2FinalHead::update()
{    
    if (pData->isDead)
    {
        explosion->update();

        if (explosion->isFinishAnimation())
        {
            this->pData->isDesTroyed = true;
            return;
        }
    }
    else
    {
        if (Boss2Final::getInstance()->isLeftArmDie() && Boss2Final::getInstance()->isRightArmDie())
        {
            this->pData->isHittable = true;
        }

        this->pData->pState->onUpdate();
    }
}

void Boss2FinalHead::draw(Camera *cam)
{
    if (pData->isDead)
    {
        explosion->draw(cam);    
        explosion->drawAtPosition(bodySprite->getBody().x, bodySprite->getBody().y + 20, cam);
    }
    else
    {
        bodySprite->draw(cam);
        pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
    }
}
