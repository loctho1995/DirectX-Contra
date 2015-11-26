#pragma once
#include "EnermyState.h"
#include "Boss2FinalData.h"
#include "Boss2FinalArmWaveState.h"
#include "Boss2FinalArmDirectPlayerState.h"

class Boss2FinalArmAttackState : public EnermyState
{
public:
    Boss2FinalArmAttackState(EnermyData *pData);
    ~Boss2FinalArmAttackState();

    void moveAround(Boss2FinalJoint* joint, Boss2FinalJoint* joint0, float deltaRadius, float speed, float frame,
        Boss2FinalJoint::MoveAroundDirection dir, float delay = 0);

    float getAngle(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2);

    void onUpdate();

private:
    int delayChangeState;
    int frameAttack;
    Boss2FinalJoint **joints;
};

