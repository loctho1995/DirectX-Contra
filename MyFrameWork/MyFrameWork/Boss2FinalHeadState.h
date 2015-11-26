#pragma once
#include "EnermyState.h"
#include "Boss2FinalData.h"
#include "Boss2FinalBullet.h"

class Boss2FinalHeadState : public EnermyState
{
public:
    Boss2FinalHeadState(EnermyData *pData);
    ~Boss2FinalHeadState();

    void onUpdate();

private:
    const int FRAME_COUNT_SHUT; //65frame
    const int FRAME_COUNT_ATTACK;
    int frameCountShut, frameCountAttack;
    bool isStartAttack;
};

