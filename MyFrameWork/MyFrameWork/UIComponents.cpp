#include "UIComponents.h"

UIComponents* UIComponents::instance = nullptr;

UIComponents* UIComponents:: getInstance()
{
	if(instance == nullptr)
	{
		instance = new UIComponents();
	}
	return instance;
}

UIComponents::UIComponents()
{
	score = 0;
	highScore = 0 ;//highScore; load through file
	currentStage = 1;
	lifes = 3;
}


UIComponents::~UIComponents()
{

}


int UIComponents:: getLifes()
{
	return lifes;
}
int UIComponents:: getScore()
{
	return score;
}
int UIComponents:: getHighScore()
{
	return highScore;
}
int UIComponents:: getCurrentStage()
{
	return currentStage;
}
void UIComponents:: inscreaseLifes()
{
	lifes++;
}
void UIComponents:: descreaseLifes()
{
	lifes--;
}
void UIComponents:: addScore( int val )
{
	if ( val != 0)
	Sound::getInstance() ->play("beep.wav", false, 1);
	score += val;
}
void UIComponents:: setStage(int val)
{
	currentStage = val;
}
void UIComponents:: gameOverReset()
{
	score = 0;
	highScore = 0 ;//highScore; load through file
	lifes = 3;
}