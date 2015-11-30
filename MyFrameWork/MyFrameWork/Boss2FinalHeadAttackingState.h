#pragma once
#include "EnermyState.h"
#include "Boss2FinalData.h"
#include "Boss2FinalBullet.h"
#include "Boss2FinalHeadOpeningState.h"

class Boss2FinalHeadAttackingState : public EnermyState
{
public:
    Boss2FinalHeadAttackingState(EnermyData *pData);
    ~Boss2FinalHeadAttackingState();
    void onUpdate();

private:
    int frameAttack;
};

