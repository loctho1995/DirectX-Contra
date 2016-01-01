#include "EnemySniperHidingState.h"
#include"EnemySniperTurningState.h"

EnemySniperHidingState::EnemySniperHidingState(EnermyData* pData)
{
    this->pData = pData;
	if (pData->stage == 2)
    this->pData->body = RectF(-15.0f / 2, -9.0f, 15.0f, 9.0f);

    this->pData->iCurrentArr = EnemySniperData::HIDING;
    rangeChangeState = 70;
    frameChangeState = 60;
}


EnemySniperHidingState::~EnemySniperHidingState()
{
}

void EnemySniperHidingState::onUpdate()
{
    EnermyState::onUpdate();

    D3DXVECTOR2 player1 = D3DXVECTOR2(pData->playerX - pData->x, pData->playerY - pData->y);
    D3DXVECTOR2 player2 = D3DXVECTOR2(pData->player2X - pData->x, pData->player2Y - pData->y);

    float length1 = D3DXVec2Length(&player1);
    float length2 = D3DXVec2Length(&player2);

    if (length1 <= 150 || length2 <= 150)
    {
		if (frameChangeState <= 0)
		{
			if (pData->stage == 2)
				this->pData->pState = new EnemySniperShowingState(this->pData);
			else
			{
				this->pData->pState = new EnemySniperStandingState(this->pData);
			}
		}
        else
        {
            frameChangeState--;
        }
    }
}
