#include "EnemyBazokaExploringState.h"
#include "Sound.h"

EnemyBazokaExploringState::EnemyBazokaExploringState(EnermyData* data)
{
	pData = data;
	pData -> iCurrentArr = 2;
	pData -> isHittable = false;
	Sound :: getInstance() -> play( "enemydead.wav", false , 1);
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