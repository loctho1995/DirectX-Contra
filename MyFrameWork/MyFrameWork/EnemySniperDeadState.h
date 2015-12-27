#pragma once
#include "EnermyState.h"


class EnemySniperDeadState : public EnermyState
{
public:
	EnemySniperDeadState(EnermyData* data);
	~EnemySniperDeadState(void);

	virtual void onUpdate();
private:
	float acc;
};