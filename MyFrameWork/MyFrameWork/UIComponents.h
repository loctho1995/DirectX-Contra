#pragma once
#include "Sound.h"

class UIComponents
{
public:
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
private:
	static UIComponents* instance;
	UIComponents();
	int score;
	int highScore;
	int currentStage;
	int lifes;
};

