#include "EnemySniperDeadState.h"
#include "EnemySniperData.h"


EnemySniperDeadState::EnemySniperDeadState(EnermyData* data)
{
	pData = data;
	pData->isHittable = false;
	pData->isThrougable = false;
	pData->vy = -4.0f;
	isExploring = false;
	bool isExplored;
	acc = 0.2f;
}

EnemySniperDeadState::~EnemySniperDeadState(void)
{
}

void EnemySniperDeadState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();

	if (!isExploring)
	{
		pData->vy += acc;
		pData->y += pData->vy;

		if (pData->vy >= 0)
		{
			isExploring = true;
			pData->iCurrentArr = EnemySniperData::DEAD;
		}
	}
	else
	{
		if (pData->ppTextureArrays[pData->iCurrentArr]->isLastTexture())
		{
			pData->isDesTroyed = true;
		}
	}
}