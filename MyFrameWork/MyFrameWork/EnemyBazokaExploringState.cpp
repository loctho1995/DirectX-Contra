#include "EnemyBazokaExploringState.h"


EnemyBazokaExploringState::EnemyBazokaExploringState(EnermyData* data)
{
	pData = data;
	pData -> iCurrentArr = 2;
	pData -> isHittable = false;

}


EnemyBazokaExploringState::~EnemyBazokaExploringState(void)
{
}

void EnemyBazokaExploringState:: onUpdate()
{
	EnermyState::onUpdate();
	if(pData -> ppTextureArrays[ pData -> iCurrentArr] ->isLastTexture())
	{
		pData -> isDesTroyed = true;
	}
}