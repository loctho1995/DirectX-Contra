#pragma once
#include "Sound.h"
#include "Windows.h"
class UIComponents
{
public:
	enum
	{
		LEFT,
		RIGHT,
		UP,
		DOWN,
		FIRE,
		JUMP,
		SELECT,
		COUNT
	} KEY;
	~UIComponents();
	static UIComponents* getInstance();
	int getLifes();
	int getScore();
	int getHighScore();
	int getCurrentStage();
	void inscreaseLifes();
	void descreaseLifes();
	void addScore( int val );
	void setStage(int val);
	void gameOverReset();
	char getKey(int index);
	void setKey(int index, char keyCode);
	char getDefaultKey(int index);
	void setDefaultKeyBoard();
	void resetStage();
private:
	static UIComponents* instance;
	UIComponents();
	const int POINT_PER_LIFE;
	int score;
	int highScore;
	int currentStage;
	int lifes;
	char configKeyBoard[COUNT];
	char defaultKeyBoard[COUNT];
};

