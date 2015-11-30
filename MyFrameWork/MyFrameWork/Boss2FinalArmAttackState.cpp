#include "Boss2FinalArmAttackState.h"


Boss2FinalArmAttackState::Boss2FinalArmAttackState(EnermyData *pData)
{
    this->pData = pData;

    float speed = 5.0f;
    float limitFrame = 100 / speed;
    frameAttack = 10;
    delayChangeState = 40;

    joints = ((Boss2FinalData*)pData)->joints;

    if (((Boss2FinalData*)pData)->armSide == Boss2FinalData::ArmSide::LEFT)
    {
        moveAround(((Boss2FinalData*)pData)->joints[1], ((Boss2FinalData*)pData)->joints[0], 0, speed,
            limitFrame, Boss2FinalJoint::MoveAroundDirection::Negative);
    }
    else
    {
        moveAround(((Boss2FinalData*)pData)->joints[1], ((Boss2FinalData*)pData)->joints[0], 0, speed,
            limitFrame, Boss2FinalJoint::MoveAroundDirection::Positive);
    }

    ((Boss2FinalData*)pData)->joints[2]->moveFollow(((Boss2FinalData*)pData)->joints[1]);
    ((Boss2FinalData*)pData)->joints[3]->moveFollow(((Boss2FinalData*)pData)->joints[2]);
    ((Boss2FinalData*)pData)->joints[4]->moveFollow(((Boss2FinalData*)pData)->joints[3]);
}

void Boss2FinalArmAttackState::moveAround(Boss2FinalJoint* joint, Boss2FinalJoint* joint0, float deltaRadius,
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

Boss2FinalArmAttackState::~Boss2FinalArmAttackState()
{
}

void Boss2FinalArmAttackState::onUpdate()
{
    if (frameAttack > 0)
    {
        frameAttack--;

        if (frameAttack == 0)
        {
            float angle = getAngle(D3DXVECTOR2(pData->playerX, pData->playerY), joints[4]->getPosition());
            pData->bulletsVector.push_back(new Boss2FinalBullet(joints[4]->getPosition().x, joints[4]->getPosition().y, 1.5f, angle));
        }
    }

    if (((Boss2FinalData*)pData)->joints[1]->isMoveAround == false)
    {
        ((Boss2FinalData*)pData)->joints[2]->moveAroundSpeed *= 0.99;
    }

    if (((Boss2FinalData*)pData)->joints[2]->isMoveAround == false)
    {
        ((Boss2FinalData*)pData)->joints[3]->moveAroundSpeed *= 1.1;
    }

    if (((Boss2FinalData*)pData)->joints[4]->isMoveAround == false && ((Boss2FinalData*)pData)->joints[1]->isMoveAround == false)
    {
        if (delayChangeState >= 0)
        {
            delayChangeState--;
        }
        else
        {
            transition(new Boss2FinalArmDirectPlayerState(this->pData));
            return;
        }
    }

    for (size_t i = 0; i < 5; i++)
    {
        ((Boss2FinalData*)pData)->joints[i]->update();
    }

    //this->pData->pState = new Boss2FinalArmWaveState(this->pData);
    //return;
}

float Boss2FinalArmAttackState::getAngle(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2)
{
    D3DXVECTOR2 vec(pos1 - pos2);
    D3DXVec2Normalize(&vec, &vec);

    float angle = acos(vec.x) * (abs(vec.y) / vec.y);

    return angle;
}