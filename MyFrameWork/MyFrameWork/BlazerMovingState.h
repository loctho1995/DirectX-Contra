#pragma once

#include "EnermyState.h"
class BlazerMovingState : public EnermyState
{
public:
	BlazerMovingState(EnermyData* data);
	~BlazerMovingState(void);
	virtual void onUpdate();
private:
	float speed;
};

