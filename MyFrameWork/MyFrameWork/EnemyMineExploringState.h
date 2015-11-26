#pragma once
#include "EnermyState.h"
class EnemyMineExploringState : public EnermyState
{
public:
	EnemyMineExploringState(EnermyData* data);
	~EnemyMineExploringState(void);
	virtual void onUpdate();
};

