#include "Boss2FinalJoint.h"


Boss2FinalJoint::Boss2FinalJoint(float x, float y)
{
    this->pData = new SpriteData();
    this->pData->ppTextureArrays = new TextureArray *[1];
    this->pData->iCurrentArr = 0;
    this->pData->x = x;
    this->pData->y = y;
    this->pData->ppTextureArrays[pData->iCurrentArr] = new TextureArray("Resources\\Sprites", "boss2final", "joint", 1, 1);    

    defaultSetting();
}

Boss2FinalJoint::~Boss2FinalJoint()
{
    //delete jointFollow;
    //jointFollow = nullptr;
}

Boss2FinalJoint::Boss2FinalJoint()
{

}

void Boss2FinalJoint::defaultSetting()
{
    this->pData->body = RectF(-8, -8, 16, 16);
    this->pData->vx = 0;
    this->pData->vy = 0;
    this->pData->ppTextureArrays[pData->iCurrentArr]->setAnchorPoint(0.5f, 0.5f);

    moveAroundDirection = MoveAroundDirection::Unknow;
    distanceMoved = 0;
    angleMoved = 0;
    moveAroundAccelemetor = 0;

    isMoveAround = false;
    isMoveTo = false;
    isMoveBy = false;
    isMoveByVelocity = false;
    isMoveFollow = false;
    allowMoveReverse = false;
    isMoveAroundAcclemetor = false;
    isJointFollowStoped = true;
    isMoveFollowFirstTime = false;
    isMoveFollowWithAccelemetor = true;

    jointFollow = nullptr;
}

void Boss2FinalJoint::update()
{
    float oldx = pData->x;
    float oldy = pData->y;

    if (isMoveAround)
    {
        updateMoveAround();
    }

    if (isMoveTo)
    {
        updateMoveTo(oldx, oldy);
    }

    if (isMoveBy)
    {
        updateMoveBy(oldx, oldy);
    }

    if (isMoveFollow)
    {
        updateMoveFollow();
    }

    currMoveDirection = D3DXVECTOR2(pData->x - oldx, pData->y - oldy);
}

void Boss2FinalJoint::setPosition(float x, float y)
{
    this->pData->x = x;
    this->pData->y = y;
}

D3DXVECTOR2 Boss2FinalJoint::getPosition()
{
    return D3DXVECTOR2(pData->x, pData->y);
}

void Boss2FinalJoint::updateMoveAround()
{
    if (moveAroundDelay > 0)
    {
        moveAroundDelay--;
    }
    else
    {
        moveAroundCurrFrame++;

        //xoay xung quanh 1 diem
        D3DXVECTOR2 pos(pData->x - moveAroundX, pData->y - moveAroundY);

        D3DXVec2Normalize(&pos, &pos);

        float angle = acos(pos.x);
        angle *= (abs(pos.y) / pos.y);

        angle += D3DXToRadian(moveAroundDirection == MoveAroundDirection::Positive ? moveAroundSpeed : -moveAroundSpeed);

        float posx = cos(angle);
        float posy = sin(angle);

        pData->x = moveAroundX + posx * moveAroundRadius;
        pData->y = moveAroundY + posy * moveAroundRadius;

        distanceMoved = abs((2 * 3.1415926f * moveAroundRadius * moveAroundSpeed) / 360);
        angleMoved += moveAroundSpeed;

        if (moveAroundFrame != -1)
        {
            if (moveAroundCurrFrame >= moveAroundFrame)
            {
                isMoveAround = false;
            }
        }

        if (moveAroundSpeed <= 0)
        {
            isMoveAround = false;
        }

        this->setMoveAroundSpeed(moveAroundSpeed - moveAroundAccelemetor);
    }
}

void Boss2FinalJoint::updateMoveBy(float oldx, float oldy)
{
    if (moveByDelay >= 0)
    {
        moveByDelay--;
    }
    else
    {
        moveByCurrFrame++;

        pData->x += pData->vx;
        pData->y += pData->vy;

        D3DXVECTOR2 dist = D3DXVECTOR2(pData->x - oldx, pData->y - oldy);
        distanceMoved += D3DXVec2Length(&dist);

        if (moveByCurrFrame >= moveByFrame)
        {
            pData->vx = 0;
            pData->vy = 0;
            isMoveBy = false;
        }
    }
}

void Boss2FinalJoint::updateMoveTo(float oldx, float oldy)
{
    if (moveToDelay > 0)
    {
        moveToDelay--;
    }
    else
    {
        moveToCurrFrame++;

        pData->x += pData->vx;
        pData->y += pData->vy;

        D3DXVECTOR2 dist = D3DXVECTOR2(pData->x - oldx, pData->y - oldy);
        distanceMoved += D3DXVec2Length(&dist);

        if (moveToCurrFrame >= moveToFrame)
        {
            pData->x = moveToX;
            pData->y = moveToY;

            pData->vx = 0;
            pData->vy = 0;

            isMoveTo = false;

        }
    }
}

void Boss2FinalJoint::updateMoveFollow()
{
    //doi huong di chuyen
    if (this->moveAroundDirection != jointFollow->moveAroundDirection)
    {
        if (!allowMoveReverse && jointFollow->isMoveAround)
        {
            if (isMoveFollowFirstTime)
            {
                if (isMoveFollowWithAccelemetor)
                {
                    this->moveAround(jointFollow->pData->x, jointFollow->pData->y, 16, -1, jointFollow->getAngleSpeed() * 0.2f, moveAroundDirection, jointFollow->getAngleSpeed() / 11.0f);
                    isMoveFollowFirstTime = false;
                }
            }
            else
            {
                if (isMoveFollowWithAccelemetor)
                {
                    this->moveAround(jointFollow->pData->x, jointFollow->pData->y, 16, -1, jointFollow->getAngleSpeed() * 0.7f, moveAroundDirection, jointFollow->getAngleSpeed() / 11.0f);
                }
            }

            allowMoveReverse = true;
        }
    }


    if (allowMoveReverse && jointFollow->isMoveAround)
    {
        if (this->moveAroundSpeed <= 0)
        {
            reverseMoveAroundDirection();
            this->setMoveAroundSpeed(jointFollow->getAngleSpeed());
            allowMoveReverse = false;                       
        }
    }

    if (!allowMoveReverse)
    {
        if (jointFollow->isMoveAround)
        {
            if (isMoveFollowWithAccelemetor)
            {
                this->moveAround(jointFollow->pData->x, jointFollow->pData->y, 16, jointFollow->getAngleSpeed() * 2.5f, moveAroundSpeed, moveAroundDirection);
            }
            else
            {
                this->moveAround(jointFollow->pData->x, jointFollow->pData->y, 16, 5, moveAroundSpeed * 12.5f, moveAroundDirection);
            }
        }
    }

    pData->vx = jointFollow->getCurrentMoveDirection().x;
    pData->vy = jointFollow->getCurrentMoveDirection().y;

    pData->x += pData->vx;
    pData->y += pData->vy;
    
    alignDistance(jointFollow);
}

//void Boss2FinalJoint::moveTo(float x, float y, int frames, int delay)
//{
//    distanceMoved = 0;
//
//    D3DXVECTOR2 vecd = D3DXVECTOR2(x - pData->x, y - pData->y);
//
//    pData->vx = vecd.x / frames;
//    pData->vy = vecd.y / frames;
//
//    moveToX = x;
//    moveToY = y;
//
//    moveToCurrFrame = 0;
//    moveToFrame = frames;
//    moveToDelay = delay;
//
//    isMoveTo = true;
//}

void Boss2FinalJoint::moveBy(float x, float y, int frames, int delay)
{
    distanceMoved = 0;

    pData->vx = x;
    pData->vy = y;

    moveByFrame = frames;
    moveByDelay = delay;
    moveByCurrFrame = 0;

    isMoveBy = true;
}

void Boss2FinalJoint::moveAround(float x, float y, float radius, int frame, float speed, MoveAroundDirection direction, float accelemetor,  int delay)
{
    distanceMoved = 0;
    angleMoved = 0;
    moveAroundX = x;
    moveAroundY = y;
    moveAroundFrame = frame;
    moveAroundCurrFrame = 0;
    moveAroundDelay = delay;
    moveAroundAccelemetor = accelemetor;
    isMoveAround = true;

    if (accelemetor != 0)
    {
        isMoveAroundAcclemetor = true;
    }
    else
    {
        isMoveAroundAcclemetor = false;
    }

    moveAroundDirection = direction;
    setMoveAroundRadius(radius);
    setMoveAroundSpeed(speed);
}

void Boss2FinalJoint::moveFollow(Boss2FinalJoint *joint, bool isMoveFollowWithAccelemetor)
{
    jointFollow = joint;
    isMoveFollow = true;
    isMoveFollowFirstTime = true;
    this->isMoveFollowWithAccelemetor = isMoveFollowWithAccelemetor;

    if (joint->isMoveAround)
    {
        isJointFollowStoped = false;
    }
    else
    {
        isJointFollowStoped = true;
    }

    pData->vx = joint->getCurrentMoveDirection().x;
    pData->vy = joint->getCurrentMoveDirection().y;
    moveAroundDirection = joint->moveAroundDirection == MoveAroundDirection::Positive ? MoveAroundDirection::Negative : MoveAroundDirection::Positive;
}

void Boss2FinalJoint::alignDistance(Boss2FinalJoint* joint2)
{
    D3DXVECTOR2 vec = (this->getPosition() - joint2->getPosition());
    float distance = 16;

    D3DXVec2Normalize(&vec, &vec);
    float angle = acos(vec.x) * (abs(vec.y) / vec.y);;

    float posx = cos(angle);
    float posy = sin(angle);

    float joint1X = joint2->getPosition().x + vec.x * distance;
    float joint1Y = joint2->getPosition().y + vec.y * distance;

    this->setPosition(joint1X, joint1Y);
}

void Boss2FinalJoint::stopMoveAround()
{
    isMoveAround = false;   
    moveAroundSpeed = 0;
    moveAroundAccelemetor = 0;
    moveAroundCurrFrame = 0;
    angleMoved = 0;
}

void Boss2FinalJoint::setMoveAroundSpeed(float speed)
{
    if (speed <= 0)
        moveAroundSpeed = 0;
    else
        moveAroundSpeed = speed;
}

void Boss2FinalJoint::setMoveAroundRadius(float radius)
{
    moveAroundRadius = radius;
}

D3DXVECTOR2 Boss2FinalJoint::getCurrentMoveDirection()
{
    return currMoveDirection;
}

float Boss2FinalJoint::getAngleSpeed()
{
    return moveAroundSpeed;
}

void Boss2FinalJoint::reverseMoveAroundDirection()
{
    if (moveAroundDirection == MoveAroundDirection::Positive)
    {
        moveAroundDirection = MoveAroundDirection::Negative;
    }
    else
    {
        moveAroundDirection = MoveAroundDirection::Positive;
    }

    this->angleMoved = 0;
}

void Boss2FinalJoint::setMoveAroundDelay(int frame)
{
    moveAroundDelay = frame;
}

void Boss2FinalJoint::stopMoveFollow()
{
    this->isMoveFollow = false;
    jointFollow = nullptr;    
}

int Boss2FinalJoint::getMoveAroundCurrFrame()
{
    return moveAroundCurrFrame;
}

void Boss2FinalJoint::draw(Camera *cam)
{
    pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
}