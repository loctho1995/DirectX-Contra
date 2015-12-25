#include "Boss2FinalArmSpinningState.h"


Boss2FinalArmSpinningState::Boss2FinalArmSpinningState(EnermyData *pData) : FRAME_ATTACK(70)
{
    this->pData = pData;
    frameAttack = FRAME_ATTACK;

    float x = ((Boss2FinalData*)pData)->joints[0]->getBody().x + ((Boss2FinalData*)pData)->joints[0]->getBody().width / 2;
    float y = ((Boss2FinalData*)pData)->joints[0]->getBody().y + ((Boss2FinalData*)pData)->joints[0]->getBody().height / 2;

    speedAngle = 5.7f;
    totalFrame = 400 / speedAngle;
    delayChangeState = 6;

    if (((Boss2FinalData*)pData)->armSide == Boss2FinalData::ArmSide::LEFT)
    {
        moveAround(((Boss2FinalData*)pData)->joints[1], ((Boss2FinalData*)pData)->joints[0], 0, speedAngle,
            totalFrame, Boss2FinalJoint::MoveAroundDirection::Positive);
    }
    else
    {
        moveAround(((Boss2FinalData*)pData)->joints[1], ((Boss2FinalData*)pData)->joints[0], 0, speedAngle,
            totalFrame, Boss2FinalJoint::MoveAroundDirection::Negative);
    }
   
    joints = ((Boss2FinalData*)pData)->joints;
    //((Boss2FinalData*)pData)->joints[2]->moveFollow(((Boss2FinalData*)pData)->joints[1]);
    //((Boss2FinalData*)pData)->joints[3]->moveFollow(((Boss2FinalData*)pData)->joints[2]);
    //((Boss2FinalData*)pData)->joints[4]->moveFollow(((Boss2FinalData*)pData)->joints[3]);
}

void Boss2FinalArmSpinningState::moveAround(Boss2FinalJoint* joint, Boss2FinalJoint* joint0, float deltaRadius,
    float speed, float frame, Boss2FinalJoint::MoveAroundDirection dir, float delay)
{
    float x = joint0->getBody().x + joint0->getBody().width / 2;
    float y = joint0->getBody().y + joint0->getBody().height / 2;

    float x2 = joint->getBody().x + joint->getBody().width / 2;
    float y2 = joint->getBody().y + joint->getBody().height / 2;

    D3DXVECTOR2 dist(x - x2, y - y2);

    //joint ngoai cung se dung lai truoc joint trong cung va hand dung lai dau tien
    //thu hep khoang cach cua joint va hand lai vi xoay khoang cach bi gian ra
    //de tao hieu ung wave thi van toc cua cac joint phai khac nhau va joint trong cung di chuyen nhanh nhat
    joint->moveAround(x, y, D3DXVec2Length(&dist) - deltaRadius, frame, speed, dir, delay);
}

Boss2FinalArmSpinningState::~Boss2FinalArmSpinningState()
{
}

void Boss2FinalArmSpinningState::onUpdate()
{
    if (frameAttack >= 0)
    {
        frameAttack--;
    }
    else
    {
        float angle = 0; 

        if (UIComponents::getInstance()->getNumberPlayer() == 1)
        {
            //chi co 1 thang player
            angle = getAngle(D3DXVECTOR2(pData->playerX, pData->playerY), joints[4]->getPosition());
        }
        else
        {
            if (pData->isPlayerDead)
            {
                //player 1 chet
                angle = getAngle(D3DXVECTOR2(pData->player2X, pData->player2Y), joints[4]->getPosition());
            }
            else if (pData->isPlayer2Dead)
            {
                //player 2 chet
                angle = getAngle(D3DXVECTOR2(pData->playerX, pData->playerY), joints[4]->getPosition());
            }
            else
            {
                //eu co thang nao chet
                D3DXVECTOR2 player1 = D3DXVECTOR2(pData->playerX, pData->playerY) - joints[4]->getPosition();
                D3DXVECTOR2 player2 = D3DXVECTOR2(pData->player2X, pData->player2Y) - joints[4]->getPosition();
                float length1 = D3DXVec2Length(&player1);
                float length2 = D3DXVec2Length(&player2);

                if (length1 < length2)
                {
                    angle = getAngle(D3DXVECTOR2(pData->playerX, pData->playerY), joints[4]->getPosition());
                }
                else
                {
                    angle = getAngle(D3DXVECTOR2(pData->player2X, pData->player2Y), joints[4]->getPosition());
                }
            }
        }

        pData->bulletsVector.push_back(new Boss2FinalBullet(joints[4]->getPosition().x, joints[4]->getPosition().y, 1.0f, angle));
        frameAttack = FRAME_ATTACK;
    }

    if (!((Boss2FinalData*)pData)->joints[1]->isMoveAround)
    {
        ((Boss2FinalData*)pData)->joints[4]->setMoveAroundSpeed(((Boss2FinalData*)pData)->joints[4]->moveAroundSpeed * 0.99f);
    }

    if (!((Boss2FinalData*)pData)->joints[4]->isMoveAround)
    {
        if (delayChangeState >= 0)
        {
            delayChangeState--;
        }
        else
        {
            transition(new Boss2FinalArmAttackState(this->pData));
            return;
        }
    }

    for (size_t i = 0; i < 5; i++)
    {
        ((Boss2FinalData*)pData)->joints[i]->update();
    }
}

float Boss2FinalArmSpinningState::getAngle(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2)
{
    D3DXVECTOR2 vec(pos1 - pos2);
    D3DXVec2Normalize(&vec, &vec);

    float angle = acos(vec.x) * (abs(vec.y) / vec.y);

    return angle;
}