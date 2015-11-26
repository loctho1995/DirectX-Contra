#pragma once
#include "EnermyState.h"
class EnemyBazokaStandingState : public EnermyState
{
public:
	EnemyBazokaStandingState(EnermyData* data);
	~EnemyBazokaStandingState(void);
	virtual void onUpdate();
	virtual void onDead();
private:
	int nHoldingFrames;
	int count;
};

