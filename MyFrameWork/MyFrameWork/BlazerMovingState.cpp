#include "BlazerMovingState.h"


BlazerMovingState::BlazerMovingState(EnermyData* data)
{
	pData = data;
	pData -> iCurrentArr = 0;
	speed = 1.0;
	pData -> vx = pData->transform(speed);
	pData -> vy = 0.0f;
}


BlazerMovingState::~BlazerMovingState(void)
{
}

void BlazerMovingState:: onUpdate()
{
	EnermyState::onUpdate();
	if( pData -> x <= pData -> cSupportRect.rect.x || pData -> x >= pData -> cSupportRect.rect.x +  pData -> cSupportRect.rect.width)
	{
		pData -> dir.reverse();
	}
	
	pData -> vx = pData -> transform(speed);

	pData -> x += pData -> vx;


}
