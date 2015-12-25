#include "GameSaveLoad.h"
GameSaveLoad* GameSaveLoad::instance = nullptr;
fstream GameSaveLoad::file;
int GameSaveLoad::currentHighScore = 0;

GameSaveLoad::GameSaveLoad()
{
    file.open("Resources//Data//save.vcl", ios::in);

    if (!file)
    {
        fopen("Resources//Data//save.vcl", "w");
        file.open("Resources//Data//save.vcl", ios::in);
    }

    string data;
    getline(file, data);
    currentHighScore = atoi(data.c_str());
    file.close();
}


GameSaveLoad::~GameSaveLoad()
{
}

unsigned int GameSaveLoad::getHighScore()
{
    return currentHighScore;
}

void GameSaveLoad::checkAndSaveScore(int score)
{
    if (score > currentHighScore)
    {        
        file.open("Resources//Data//save.vcl", ios::out);
        file << score;
        currentHighScore = score;
        file.close();
    }
}

GameSaveLoad* GameSaveLoad::getInstance()
{
    if (!instance)
    {
        instance = new GameSaveLoad();
    }

    return instance;
}
