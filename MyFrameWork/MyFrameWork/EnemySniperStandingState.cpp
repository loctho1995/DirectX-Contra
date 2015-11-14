#include "EnemySniperStandingState.h"
#include "EnemySniperData.h"
#include "EnemySniperTurningState.h"



EnemySniperStandingState::EnemySniperStandingState(EnermyData* data)
{
	this->pData = data;
	nHoldFrames = 90;
	count = 0;
}

EnemySniperStandingState::~EnemySniperStandingState()
{
}

void EnemySniperStandingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();

	count++;
	count %= nHoldFrames;

	if (count == 0)
	{
		transition(new EnemySniperTurningState(pData));
	}
}

void EnemySniperStandingState:: onDead()
{
	transition(new EnemySniperDeadState(pData));
}