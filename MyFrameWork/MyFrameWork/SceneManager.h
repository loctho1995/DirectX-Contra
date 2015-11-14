#pragma once


#include "MenuScene.h" // just abstract class 
#include "PlayScene.h"
#include "LoadingScene.h"
#include "StartingScene.h"
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
		{
			if(pCurrentScene)
			 delete pCurrentScene;
			pCurrentScene = scene;
		}
	}
	Scene* getCurrentScene() { return pCurrentScene ;}
private:
	SceneManager() 
	{
		pCurrentScene = NULL;
	}
	static SceneManager* pInstance;
	Scene* pCurrentScene;
};
