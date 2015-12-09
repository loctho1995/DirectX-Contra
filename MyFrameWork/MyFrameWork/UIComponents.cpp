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
	:
	POINT_PER_LIFE( 25000)
{
	score = 0;
	highScore = 0 ;//highScore; load through file
	currentStage = 5;
	lifes = 5;
	configKeyBoard[LEFT] = defaultKeyBoard[LEFT] = VK_LEFT;
	configKeyBoard[RIGHT] = defaultKeyBoard[RIGHT] = VK_RIGHT;
	configKeyBoard[UP] = defaultKeyBoard[UP] = VK_UP;
	configKeyBoard[DOWN] = defaultKeyBoard[DOWN] = VK_DOWN;
	configKeyBoard[FIRE] = defaultKeyBoard[FIRE] = 0x46;
	configKeyBoard[JUMP] = defaultKeyBoard[JUMP] = VK_SPACE;
	configKeyBoard[SELECT] = defaultKeyBoard[SELECT] = VK_RETURN;
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
	if( (( score + val ) / POINT_PER_LIFE ) > ( score / POINT_PER_LIFE ) )
	{
		inscreaseLifes();
	}
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

char UIComponents :: getKey(int index)
{
	return configKeyBoard[index];
}

char UIComponents :: getDefaultKey(int index)
{
	return defaultKeyBoard[index];
}

void UIComponents :: setKey(int index, char keyCode)
{
	for (int i = 0; i < COUNT; i++)
	{
		if(configKeyBoard[i] == keyCode && i != index)
		{
			configKeyBoard[i] = configKeyBoard[index];
			configKeyBoard[index] = keyCode;
			return;
		}
	}
	configKeyBoard[index] = keyCode;
}

void UIComponents :: setDefaultKeyBoard()
{
	memccpy(configKeyBoard, defaultKeyBoard, NULL, sizeof(configKeyBoard));
}

