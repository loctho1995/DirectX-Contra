#pragma once
#include "EnermyState.h"
#include "EnermyData.h"
#include "EnemySniperHidingState.h"
#include "EnermyWhiteBullet.h"

class EnemySniperShowingState : public EnermyState
{
public:
    EnemySniperShowingState(EnermyData* data);
    ~EnemySniperShowingState();
	virtual void onDead();

    virtual void onUpdate();

private:
    int frameToShot;
    int shotCount;
};

