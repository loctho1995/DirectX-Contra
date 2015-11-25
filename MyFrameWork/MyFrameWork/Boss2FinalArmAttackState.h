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


    void onUpdate();

private:
    int delayChangeState;
};

