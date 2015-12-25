#include "Boss2FinalArmDirectPlayerState.h"


Boss2FinalArmDirectPlayerState::Boss2FinalArmDirectPlayerState(EnermyData *pData)
{
    this->pData = pData;
    isFirstTime = true;

    timeAttack = 60;

    joints = ((Boss2FinalData*)pData)->joints;
    speed = 5.0f;
    frameDelayChangeState = 280;
    
    for (size_t i = 2; i < 5; i++)
    {
        joints[i]->moveFollow(joints[i - 1], false); 
    }

    for (size_t i = 1; i < 5; i++)
    {
        joints[i]->stopMoveFollow();
        moveAroundDirect(joints[0], joints[i], speed, 15 * i);
    }    
}


Boss2FinalArmDirectPlayerState::~Boss2FinalArmDirectPlayerState()
{
}

void Boss2FinalArmDirectPlayerState::onUpdate()
{  
    if (timeAttack > 0)
    {
        timeAttack--;

        if (timeAttack == 0)
        {
            //float angle = getAngle(D3DXVECTOR2(pData->playerX, pData->playerY), joints[4]->getPosition());
            float angle = getAngle(getNearestPlayer(), joints[4]->getPosition());
            pData->bulletsVector.push_back(new Boss2FinalBullet(joints[4]->getPosition().x, joints[4]->getPosition().y, 1.0f, angle));
        }
    }

    frameDelayChangeState--;

    if (frameDelayChangeState <= 0)
    {
        transition(new Boss2FinalArmWaveState(this->pData));
        return;
    }

    if (!joints[1]->isMoveAround)
    {
        isFirstTime = false;
    }

    for (size_t i = 1; i < 5; i++)
    {
        if (!joints[i]->isMoveAround)
        {
            if (abs(getAngleBetweenPlayerAndjoint(joints[i])) >= 5.0f)
            {
                moveAroundDirect(joints[0], joints[i], speed, 15 * i);
            }
        }
    }

    for (size_t i = 2; i < 5; i++)
    {
        joints[i]->alignDistance(joints[i - 1]);
    }

    for (size_t i = 0; i < 5; i++)
    {
        ((Boss2FinalData*)pData)->joints[i]->update();
    }
}

float Boss2FinalArmDirectPlayerState::getAngle2Vector(D3DXVECTOR2 vec1, D3DXVECTOR2 vec2)
{
    D3DXVec2Normalize(&vec1, &vec1);
    D3DXVec2Normalize(&vec2, &vec2);

    float angle1 = acos(vec1.x) * (abs(vec1.y) / vec1.y);
    float angle2 = acos(vec2.x)* (abs(vec2.y) / vec2.y);;

    float result = angle2 - angle1;

    return result;
}

float Boss2FinalArmDirectPlayerState::getAngleBetweenPlayerAndjoint(Boss2FinalJoint* joint)
{
    D3DXVECTOR2 playerPos;// (((Boss2FinalData*)pData)->playerX, ((Boss2FinalData*)pData)->playerY);
    playerPos = getNearestPlayer();

    float angle = D3DXToDegree(getAngle2Vector(joint->getPosition() - joints[0]->getPosition(),
                                playerPos - joints[0]->getPosition()));

    return angle;
}

void Boss2FinalArmDirectPlayerState::moveAroundDirect(Boss2FinalJoint* joint0, Boss2FinalJoint *joint,float speed, float radius)
{   
    D3DXVECTOR2 playerPos;
    playerPos = getNearestPlayer();//(((Boss2FinalData*)pData)->playerX, ((Boss2FinalData*)pData)->playerY);

    float angle = D3DXToDegree(getAngle2Vector(joint->getPosition() - joint0->getPosition(),
        playerPos - joint0->getPosition()));

    int frameMove = abs(angle / speed);

    if (isFirstTime)
    {
        //lan dau tien tay trai se di ve ben trai, tay phai di huong ben phai
        //lan sau thi di chuyen theo do lech 
        //do lech goc
        if (((Boss2FinalData*)pData)->armSide == Boss2FinalData::ArmSide::LEFT)
        {
            if (angle > 0)
                frameMove = abs((360 - angle) / speed);

            joint->moveAround(joint0->getPosition().x, joint0->getPosition().y, radius, frameMove, speed, Boss2FinalJoint::MoveAroundDirection::Negative);
        }
        else
        {
            joint->moveAround(joint0->getPosition().x, joint0->getPosition().y, radius, frameMove, speed, Boss2FinalJoint::MoveAroundDirection::Positive);
        }
    }
    else
    {
        if (angle < 0)
        {
            joint->moveAround(joint0->getPosition().x, joint0->getPosition().y, radius, frameMove, speed, Boss2FinalJoint::MoveAroundDirection::Negative);
        }
        else
        {
            joint->moveAround(joint0->getPosition().x, joint0->getPosition().y, radius, frameMove, speed, Boss2FinalJoint::MoveAroundDirection::Positive);
        }
    }
}

float Boss2FinalArmDirectPlayerState::getAngle(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2)
{
    D3DXVECTOR2 vec(pos1 - pos2);
    D3DXVec2Normalize(&vec, &vec);

    float angle = acos(vec.x) * (abs(vec.y) / vec.y);

    return angle;
}

D3DXVECTOR2 Boss2FinalArmDirectPlayerState::getNearestPlayer()
{
    if (UIComponents::getInstance()->getNumberPlayer() == 1)
    {
        //chi co 1 thang player
        return  D3DXVECTOR2(pData->playerX, pData->playerY);
    }
    else
    {
        if (pData->isPlayerDead)
        {
            //player 1 chet
            return D3DXVECTOR2(pData->player2X, pData->player2Y);
        }
        else if (pData->isPlayer2Dead)
        {
            //player 2 chet
            return  D3DXVECTOR2(pData->playerX, pData->playerY);
        }
        else
        {
            D3DXVECTOR2 player1 = D3DXVECTOR2(pData->playerX, pData->playerY) - joints[4]->getPosition();
            D3DXVECTOR2 player2 = D3DXVECTOR2(pData->player2X, pData->player2Y) - joints[4]->getPosition();
            float length1 = D3DXVec2Length(&player1);
            float length2 = D3DXVec2Length(&player2);
            //return player1;

            if (length1 < length2)
            {
                return  D3DXVECTOR2(pData->playerX, pData->playerY);
            }
            else
            {
                return D3DXVECTOR2(pData->player2X, pData->player2Y);
            }
        }
    }
}