#include "EnemyBazokaStandingState.h"
#include "EnemyBazokaFiringState.h"
#include "EnemyBazokaExploringState.h"

EnemyBazokaStandingState::EnemyBazokaStandingState(EnermyData* data)
{
	this -> pData = data;
	pData -> iCurrentArr = 0;
	count = 0;
	nHoldingFrames = 60;
}


void EnemyBazokaStandingState:: onUpdate()
{
	EnermyState::onUpdate();
	count++;
	if( count >= nHoldingFrames )
	{
		transition(new EnemyBazokaFiringState(pData ));
	}
}

void EnemyBazokaStandingState::  onDead()
{
	transition(new EnemyBazokaExploringState(pData ));
}

EnemyBazokaStandingState::~EnemyBazokaStandingState(void)
{
}
