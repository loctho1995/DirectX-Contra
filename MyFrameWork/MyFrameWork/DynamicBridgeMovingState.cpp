#include "DynamicBridgeMovingState.h"


DynamicBridgeMovingState::DynamicBridgeMovingState(ObjectData* data)
{
	this -> pData = data;
	pData -> iCurrentArr = 0;
	speed = 1.0;
	trajectoryStart = pData -> x;
	trajectoryEnd = pData -> x + 80.0f;
	pData -> vx = pData -> transform(speed);
}


DynamicBridgeMovingState::~DynamicBridgeMovingState(void)
{
}

void DynamicBridgeMovingState :: onUpdate()
{
	ObjectState::onUpdate();
	if( pData -> x < trajectoryStart || pData -> x > trajectoryEnd)
	{
		pData -> dir.reverse();
	}
	
	pData -> vx = pData -> transform(speed);

	pData -> x += pData -> vx;
}


