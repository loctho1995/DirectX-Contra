#pragma once
#include "EnermyState.h"
class EnemyBazokaExploringState : public EnermyState
{
public:
	EnemyBazokaExploringState(EnermyData* data);
	~EnemyBazokaExploringState(void);
	virtual void onUpdate();
};

