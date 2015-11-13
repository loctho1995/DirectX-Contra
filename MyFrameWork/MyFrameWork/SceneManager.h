#pragma once


#include "MenuScene.h" // just abstract class 
#include "PlayScene.h"
#include "TestScene.h"
class SceneManager
{
public:
	static SceneManager* getInstance() 
	{
		if(pInstance == nullptr )
		{
			pInstance = new SceneManager();
		}
		return pInstance;
	}
	void createScene(Scene* scene )
	{
		if(scene)
			pCurrentScene = scene;
	}
	Scene* getCurrentScene() { return pCurrentScene ;}
private:
	SceneManager() {}
	static SceneManager* pInstance;
	Scene* pCurrentScene;
};
