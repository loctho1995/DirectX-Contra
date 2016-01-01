#pragma once
#include "Sound.h"
#include "Windows.h"
class Score
{
private:
    int score;
    std::string date;
    Score* nextScore; // the next score in the list
    //private int index;

public :
	const int NSCORES;
	Score(int score, std::string date) 
		:
		score(score),
		date(date),
		nextScore(NULL),
		NSCORES(5)
	{
        score = score;
        date = date;
    }
	Score()
		:
		NSCORES(5)
	{
		score = 0;
		date = "";
		nextScore = NULL;
	}

    bool add(Score* score) 
	{
        if (score -> getScore() > this -> score) {
            score -> setNextScore(this);
            return true;
        } else {
            if (this -> nextScore == NULL) {
                this -> setNextScore(score);
                score -> nextScore = NULL;
                return false;
            } else {
                if (this -> nextScore -> add(score) == true) {
                    this -> setNextScore(score);
                }
                return false;
            }
        }
    }

    int getScore() {
        return score;
    }

    void setNextScore(Score* nextScore) {
        this -> nextScore = nextScore;
    }

	std :: string getDate() {
        return date;
    }

    void trim() { // ensure that is the list just has 10 score
        Score* temp = this;
        int count = 1;
        while (temp -> nextScore != NULL) 
		{
			count++;
            temp = temp -> nextScore;
            if (count == NSCORES) {
                temp -> nextScore = NULL;
            }
        }
    }

    Score* getNextScore() {
        return nextScore;
    }
	int getNscores()
	{
		return NSCORES;
	}
};

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
	int getHighScore( int index = 0 );
	Score* getHighScoreObject();
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
	void serialize();
	void loadHiScore();
	void cleanUp();
private:
	static UIComponents* instance;
	UIComponents();
	const int POINT_PER_LIFE;
	int score[2];
	Score* hiScore;
	int currentStage;
	int lifes[2];
	unsigned int nPlayers;
	char configKeyBoard[2][COUNT];
	char defaultKeyBoard[2][COUNT];
};

