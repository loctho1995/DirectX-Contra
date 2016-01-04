#pragma once
#include "Scene.h"
#include "MenuScene.h"
#include "SceneManager.h"
#include "Sound.h"
#include "Texture.h"

class HighScoreScene : public Scene
{
public:
	HighScoreScene(void);
	~HighScoreScene(void);
	void render();
	void onUpdate();
	virtual void handleInput();
private:
	Label tittle;
	Label **label;
	Texture* pCursor;
	
};

