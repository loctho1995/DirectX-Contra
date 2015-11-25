#pragma once
#include "EnermyState.h"
#include "Boss2FinalData.h"

class Boss2FinalHeadState : public EnermyState
{
public:
    Boss2FinalHeadState(EnermyData *pData);
    ~Boss2FinalHeadState();

    void onUpdate();

private:
    const int FRAME_COUNT_SHUT = 165; //65frame
    int frameCountShut;
};

