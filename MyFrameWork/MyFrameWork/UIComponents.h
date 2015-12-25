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
	int getLifes(int index);
	int getScore(int index);
	int getHighScore();
	int getCurrentStage();
	void inscreaseLifes(int index);
	void descreaseLifes(int index);
	void addScore( int val , int index);
	void setStage(int val);
	void gameOverReset();
	char getKey(int index, int playerindex);
	void setKey(int index, char keyCode, int playerindex);
	char getDefaultKey(int index, int playerindex);
	void setDefaultKeyBoard();
	void resetStage();
	unsigned int getNumberPlayer();
	void setNumberPlayer( int val );
	void newStage();
	bool isAllowedKey(char keyCode);
private:
	static UIComponents* instance;
	UIComponents();
	const int POINT_PER_LIFE;
	int score[2];
	int highScore;
	int currentStage;
	int lifes[2];
	unsigned int nPlayers;
	char configKeyBoard[2][COUNT];
	char defaultKeyBoard[2][COUNT];
};

