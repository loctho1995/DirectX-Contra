#include "EnemyBazokaFiringState.h"
#include "MBullet.h"
#include "EnemyBazokaStandingState.h"
#include "EnemyBazokaExploringState.h"
#include "Sound.h"
EnemyBazokaFiringState::EnemyBazokaFiringState(EnermyData* data)
{
	this -> pData = data;
	pData -> iCurrentArr = 1;
	counter = 0;
	nHoldingFrames = 10;
}


EnemyBazokaFiringState::~EnemyBazokaFiringState(void)
{
}

void EnemyBazokaFiringState::onUpdate()
{
	EnermyState::onUpdate();
	if(counter == 0)
	{
		Sound:: getInstance() -> play("shootM", false, 1);
		pData -> bulletsVector.push_back(new MBullet(pData -> x - pData -> ppTextureArrays[pData -> iCurrentArr] -> getWidth() /2, pData -> y - 25, 3.0f, M_PI));
	}
	counter ++;
	if(counter >= nHoldingFrames )
	{
		transition(new EnemyBazokaStandingState(pData));
	}
}


void EnemyBazokaFiringState::  onDead()
{
	transition(new EnemyBazokaExploringState(pData ));
}