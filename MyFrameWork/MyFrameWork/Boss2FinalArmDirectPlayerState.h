#pragma once
#include "Boss2FinalArmWaveState.h"
#include "EnermyState.h"
#include "Boss2FinalData.h"

class Boss2FinalArmDirectPlayerState : public EnermyState
{
public:
    Boss2FinalArmDirectPlayerState(EnermyData *pData);
    ~Boss2FinalArmDirectPlayerState();

    void onUpdate();

private:
    //goc cua vec1 so voi vec2
    float getAngle2Vector(D3DXVECTOR2 vec1, D3DXVECTOR2 vec2);
    float getAngleBetweenPlayerAndjoint(Boss2FinalJoint* joint);
    D3DXVECTOR2 getNearestPlayer();
    void moveAroundDirect(Boss2FinalJoint* joint0, Boss2FinalJoint *joint, float speed, float radius = 16);
    float getAngle(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2);
    Boss2FinalJoint** joints;
    float speed;
    bool isFirstTime;
    int frameDelayChangeState;
    int timeAttack;
};

