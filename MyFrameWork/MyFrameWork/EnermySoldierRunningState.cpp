#include "EnermySoldierRunningState.h"
#include "EnermySoldierData.h"

EnermySoldierRunningState::EnermySoldierRunningState(EnermyData *pData)
{
    this->pData = pData;
    this->pData->iCurrentArr = EnermySoldierData::RUN;
    this->pData->vx = 1.0f;
    this->pData->vy = 1.0f;
    acceleration = 1.5f;
    isFallDown = false;
    frameShot = rand() % 10 + 15;
}


EnermySoldierRunningState::~EnermySoldierRunningState()
{

}

void EnermySoldierRunningState::onUpdate()
{
    if (((EnermySoldierData*)pData)->isShooter)
    {
        if (frameShot >= 0)
        {
            frameShot--;
        }
        else
        {
            if (!((EnermySoldierData*)pData)->isShooted)
            {
                ((EnermySoldierData*)pData)->isShooted = true;
                transition(new EnermySoldierShootingState(this->pData));
                return;
            }
        }
    }

    if (!isFallDown)
        EnermyState::onUpdate();
    else
    {
        //luc nay enemy dang bi roi xuong
        this->pData->vy += acceleration;
    }

    if (pData->dir.isLeft())
    {
        pData->x -= pData->vx;
    }
    else if (pData->dir.isRight())
    {
        pData->x += pData->vx;
    }

    pData->y += pData->vy;

    if (pData->cSupportRect == CollisionRectF())
    {
        transition(new EnermySoldierFallingState(this->pData));
    }
}

//void EnermySoldierRunningState::onCollision(RectF rect)
//{
//
//}

void EnermySoldierRunningState::onCollision(CollisionRectF rect)
{
    float distanceLeft = this->pData->getBody().x - rect.rect.x;
    float distanceRight = this->pData->getBody().x - (rect.rect.x + rect.rect.width);

    if (distanceLeft <= SOLDIER_RANGE_TO_JUMP)
    {
        if (rand() % 3 != 0)
        {
            transition(new EnermySoldierJumpingState(pData));
            return;
        }            
        else
        {
            this->pData->dir = Direction::createRight();
        }
    }

    if (-distanceRight <= SOLDIER_RANGE_TO_JUMP)
    {
        this->pData->dir = Direction::createLeft();
    }

    //xac dinh vi tri va cham
    //lay tam cua vat collision
    D3DXVECTOR2 colcenter = D3DXVECTOR2(rect.rect.x + rect.rect.width / 2, rect.rect.y + rect.rect.height / 2);

    //lay tam cua enemy
    RectF enrect = this->pData->getBody();
    D3DXVECTOR2 encenter = D3DXVECTOR2(enrect.x + enrect.width / 2, enrect.y + enrect.height / 2);

    //tinh toan vector huong tu enemy toi vat collision tu do xac dinh side coliision
    D3DXVECTOR2 direction = encenter - colcenter;

    if (this->pData->vy > 0 && direction.y <= 0)
    {
        //va cham ben tren (enemy ben tren vat collision)
        this->pData->vy = 0;
    }
}
