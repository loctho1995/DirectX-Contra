#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class GameSaveLoad
{
public:
    ~GameSaveLoad();

    unsigned int getHighScore();
    void checkAndSaveScore(int score);
    static GameSaveLoad* getInstance();

private:
    GameSaveLoad();
    static GameSaveLoad* instance;
    //static FILE *file;
    static int currentHighScore;
    static fstream file;
};

