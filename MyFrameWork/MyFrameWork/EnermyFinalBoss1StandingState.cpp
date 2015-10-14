#include "EnermyFinalBoss1StandingState.h"
#include "EnermyFinalBoss1DeadState.h"

EnermyFinalBoss1StandingState::EnermyFinalBoss1StandingState( EnermyData* data )
{
	pData  = data;
	pData -> iCurrentArr = 0;
	pData -> isHittable = true;
}


EnermyFinalBoss1StandingState::~EnermyFinalBoss1StandingState()
{
}

void EnermyFinalBoss1StandingState:: onUpdate() 
{
	pData ->ppTextureArrays[ pData ->iCurrentArr ] ->update();
}
void EnermyFinalBoss1StandingState::onDead()
{
	transition(new EnermyFinalBoss1DeadState(pData ));
}