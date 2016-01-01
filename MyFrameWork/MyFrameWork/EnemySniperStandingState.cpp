#include "EnemySniperStandingState.h"
#include "EnemySniperData.h"
#include "EnemySniperTurningState.h"



EnemySniperStandingState::EnemySniperStandingState(EnermyData* data)
{
	this->pData = data;
	count = 0;
	pData->iCurrentArr = EnemySniperData::HIDING2;
}

EnemySniperStandingState::~EnemySniperStandingState()
{
}

void EnemySniperStandingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();

	count++;

	if (count == 10)
	{
		transition(new EnemySniperTurningState(pData));
	}
}