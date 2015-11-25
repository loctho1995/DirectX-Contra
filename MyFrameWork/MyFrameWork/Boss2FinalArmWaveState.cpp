#include "Boss2FinalArmWaveState.h"


Boss2FinalArmWaveState::Boss2FinalArmWaveState(EnermyData *pData)
{
    this->pData = pData;

    moveAroundDelay = 0;

    float x = ((Boss2FinalData*)pData)->joints[0]->getBody().x + ((Boss2FinalData*)pData)->joints[0]->getBody().width / 2;
    float y = ((Boss2FinalData*)pData)->joints[0]->getBody().y + ((Boss2FinalData*)pData)->joints[0]->getBody().height / 2;

    speed = 5.0f;
    currFrame = 0;
    
    if (((Boss2FinalData*)pData)->armSide == Boss2FinalData::ArmSide::LEFT)
    {
        moveAround(((Boss2FinalData*)pData)->joints[1], ((Boss2FinalData*)pData)->joints[0], 0, speed,
            -1, Boss2FinalJoint::MoveAroundDirection::Negative);
    }
    else
    {
        moveAround(((Boss2FinalData*)pData)->joints[1], ((Boss2FinalData*)pData)->joints[0], 0, speed,
            -1, Boss2FinalJoint::MoveAroundDirection::Positive);
    }
    
    ((Boss2FinalData*)pData)->joints[2]->moveFollow(((Boss2FinalData*)pData)->joints[1]);
    ((Boss2FinalData*)pData)->joints[3]->moveFollow(((Boss2FinalData*)pData)->joints[2]);
    ((Boss2FinalData*)pData)->joints[4]->moveFollow(((Boss2FinalData*)pData)->joints[3]);
}

Boss2FinalArmWaveState::~Boss2FinalArmWaveState()
{

}

void Boss2FinalArmWaveState::moveAround(Boss2FinalJoint* joint, Boss2FinalJoint* joint0, float deltaRadius,
                                                float speed, float frame,Boss2FinalJoint::MoveAroundDirection dir, float delay)
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

void Boss2FinalArmWaveState::onUpdate()
{    
    float angle = getAngle(((Boss2FinalData*)pData)->joints[1]->getPosition(), ((Boss2FinalData*)pData)->joints[0]->getPosition());

    switch (((Boss2FinalData*)pData)->joints[1]->moveAroundDirection)
    {
        case Boss2FinalJoint::MoveAroundDirection::Positive:
            //doi huong chuyen dong

            if (((Boss2FinalData*)pData)->armSide == Boss2FinalData::ArmSide::LEFT)
            {
                //nguoc chuyen huong chuyen dong cua tay trai
                //positive la tay trai quay len tren
                if (angle < 0 && angle > D3DXToRadian(-60))
                {
                    currFrame++;
                    ((Boss2FinalData*)pData)->joints[1]->setMoveAroundSpeed(speed);
                    ((Boss2FinalData*)pData)->joints[1]->reverseMoveAroundDirection();
                    ((Boss2FinalData*)pData)->joints[1]->setMoveAroundDelay(moveAroundDelay);
                }
            }
            else
            {
                //tay phai
                //positive la tay phai quay xuong duoi
                if (angle > 0 && angle > D3DXToRadian(100))
                {
                    currFrame++;
                    ((Boss2FinalData*)pData)->joints[1]->setMoveAroundSpeed(speed);
                    ((Boss2FinalData*)pData)->joints[1]->reverseMoveAroundDirection();
                    ((Boss2FinalData*)pData)->joints[1]->setMoveAroundDelay(moveAroundDelay);
                }
            }

            break;

        case Boss2FinalJoint::MoveAroundDirection::Negative:
            //doi huong chuyen dong
            //nguoc lai voi positive
            if (((Boss2FinalData*)pData)->armSide == Boss2FinalData::ArmSide::LEFT)
            {
                if (angle > 0 && angle < D3DXToRadian(80))
                {
                    currFrame++;
                    ((Boss2FinalData*)pData)->joints[1]->setMoveAroundSpeed(speed);
                    ((Boss2FinalData*)pData)->joints[1]->reverseMoveAroundDirection();
                    ((Boss2FinalData*)pData)->joints[1]->setMoveAroundDelay(moveAroundDelay);
                }
            }
            else
            {
                if (angle < 0 && angle < D3DXToRadian(-120))
                {
                    currFrame++;
                    ((Boss2FinalData*)pData)->joints[1]->setMoveAroundSpeed(speed);
                    ((Boss2FinalData*)pData)->joints[1]->reverseMoveAroundDirection();
                    ((Boss2FinalData*)pData)->joints[1]->setMoveAroundDelay(moveAroundDelay);
                }
            }            
            break;
    }

    if (currFrame >= 6)
    {
        transition(new Boss2FinalArmSpinningState(this->pData));
        return;
    }

    for (size_t i = 0; i < 5; i++)
    {
        ((Boss2FinalData*)pData)->joints[i]->update();
    }
}

float Boss2FinalArmWaveState::getAngle(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2)
{
    D3DXVECTOR2 vec(pos1 - pos2);
    D3DXVec2Normalize(&vec, &vec);

    float angle = acos(vec.x) * (abs(vec.y) / vec.y);

    return angle;
}