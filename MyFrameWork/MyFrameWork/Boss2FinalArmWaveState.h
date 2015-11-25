#pragma once
#include "EnermyState.h"
#include "Boss2FinalData.h"
#include "Boss2FinalArmSpinningState.h"

class Boss2FinalArmWaveState : public EnermyState
{
public:
    Boss2FinalArmWaveState(EnermyData *pData);
    ~Boss2FinalArmWaveState();

    void onUpdate();

private:
    float limitFrame; //degree
    float speed; //degree / frame
    int currFrame, changeStateFrame;   
    int moveAroundDelay;

    std::vector<D3DXVECTOR2> listJoint1Angle;

    void moveAround(Boss2FinalJoint* joint, Boss2FinalJoint* joint0, float deltaRadius, float speed, float frame,
                            Boss2FinalJoint::MoveAroundDirection dir, float delay = 0);

    //lay goc giua 2 diem
    float getAngle(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2);
};

