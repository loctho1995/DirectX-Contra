#include "UIComponents.h"
#include "Sound.h"
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
	POINT_PER_LIFE( 15000 )
{
	for (int i = 0; i < 2; i++)
	{
		score[i] = 0;
		lifes[i] = 3;
	}
	
	highScore = 0 ;//highScore; load through file

	currentStage = 1;
	nPlayers = 0;



	configKeyBoard[0][LEFT] = defaultKeyBoard[0][LEFT] = 0x41; // A
	configKeyBoard[0][RIGHT] = defaultKeyBoard[0][RIGHT] = 0x44; // D
	configKeyBoard[0][UP] = defaultKeyBoard[0][UP] = 0x57; // W
	configKeyBoard[0][DOWN] = defaultKeyBoard[0][DOWN] = 0x53; // S
	configKeyBoard[0][FIRE] = defaultKeyBoard[0][FIRE] = 0x4A; // J
	configKeyBoard[0][JUMP] = defaultKeyBoard[0][JUMP] = 0x4B; // K
	configKeyBoard[0][SELECT] = defaultKeyBoard[0][SELECT] = VK_RETURN;

	configKeyBoard[1][LEFT] = defaultKeyBoard[1][LEFT] = VK_LEFT;
	configKeyBoard[1][RIGHT] = defaultKeyBoard[1][RIGHT] = VK_RIGHT;
	configKeyBoard[1][UP] = defaultKeyBoard[1][UP] = VK_UP;
	configKeyBoard[1][DOWN] = defaultKeyBoard[1][DOWN] = VK_DOWN;
	configKeyBoard[1][FIRE] = defaultKeyBoard[1][FIRE] = VK_NUMPAD1;
	configKeyBoard[1][JUMP] = defaultKeyBoard[1][JUMP] = VK_NUMPAD2;
	configKeyBoard[1][SELECT] = defaultKeyBoard[1][SELECT] = VK_RETURN;
}


UIComponents::~UIComponents()
{

}


int UIComponents:: getLifes(int index)
{
	return lifes[index];
}
int UIComponents:: getScore(int index)
{
	return score[index];
}
int UIComponents:: getHighScore()
{
	return highScore;
}
int UIComponents:: getCurrentStage()
{
	return currentStage;
}
void UIComponents:: inscreaseLifes(int index)
{
	Sound::getInstance() -> play("addlife", false, 1);
	lifes[index]++;
}
void UIComponents:: descreaseLifes(int index)
{
	lifes[index]--;
	int templifes = 0;
	for (int i = 0; i < nPlayers; i++)
	{
		templifes+= lifes[i];
	}
	if(templifes == 0)	
	{
		Sound::getInstance() -> stop();
	}
}
void UIComponents:: addScore( int val , int index)
{
	if ( val != 0);
		//Sound::getInstance() ->play("beep.wav", false, 1);
	if( (( score[index] + val ) / POINT_PER_LIFE ) > ( score[index] / POINT_PER_LIFE ) )
	{
		inscreaseLifes(index);
	}
	score[index] += val;
}
void UIComponents:: setStage(int val)
{
	currentStage = val;
}
void UIComponents:: resetStage()
{
	currentStage = 5;
}
void UIComponents:: gameOverReset()
{
	for (int i = 0; i < 2; i++)
	{
		score[i ] = 0;
		//highScore = 0 ;//highScore; load through file
		lifes[i] = 3;
	}
	
}

char UIComponents :: getKey(int index, int playerindex)
{
	return configKeyBoard[playerindex][index];
}

char UIComponents :: getDefaultKey(int index, int playerindex)
{
	return defaultKeyBoard[playerindex][index];
}

void UIComponents :: setKey(int index, char keyCode, int playerindex)
{
	for (int i = 0; i < COUNT - 1; i++)
	{
		for (int j = 0; j < 2; j++) // 2 is number players
		{
			if(configKeyBoard[j][i] == keyCode && (i != index || j != playerindex))
			{
				configKeyBoard[j][i] = configKeyBoard[playerindex][index];
				configKeyBoard[playerindex][index] = keyCode;
					return;
			}
		}
		
	}
	configKeyBoard[playerindex][index] = keyCode;
}

void UIComponents :: setDefaultKeyBoard()
{
	memccpy(configKeyBoard, defaultKeyBoard, NULL, sizeof(configKeyBoard));
}

void UIComponents :: setNumberPlayer( int val )
{
	nPlayers = val;
}
unsigned int UIComponents :: getNumberPlayer()
{
	return nPlayers;
}
void UIComponents :: newStage()
{
	for (int i = 0; i < 2; i++)
	{
		if(lifes[i] <= 0)
		{
			lifes[i]++;
		}
	}
}

bool UIComponents :: isAllowedKey(char keyCode)
{
	if( keyCode >= 65 && keyCode <= 90 || ( keyCode >= VK_NUMPAD0 && keyCode <= VK_NUMPAD9))
	{
		return true;
	}
	for (int i = 0; i < COUNT; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if( defaultKeyBoard[j][i] == keyCode )
				return true;
		}
	}

	return false;
}
