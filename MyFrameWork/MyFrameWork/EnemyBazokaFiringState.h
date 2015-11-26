#pragma once
#include "EnermyState.h"
class EnemyBazokaFiringState : public EnermyState
{
public:
	EnemyBazokaFiringState(EnermyData* data);
	~EnemyBazokaFiringState(void);
	virtual void onUpdate();
	virtual void onDead();
private:
	int counter;
	int nHoldingFrames;
};

