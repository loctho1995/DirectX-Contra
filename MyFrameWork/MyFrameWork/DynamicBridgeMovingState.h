#pragma once
#include "ObjectState.h"
class DynamicBridgeMovingState : public ObjectState
{
public:
	DynamicBridgeMovingState(ObjectData* data);
	~DynamicBridgeMovingState();
	virtual void onUpdate();
private:
	float speed;
	float trajectoryStart;
	float trajectoryEnd;
};

