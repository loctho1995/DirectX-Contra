#pragma once
#include "MenuScene.h" // just abstract class 
#include "PlayScene.h"
#include "LoadingScene.h"
#include "StartingScene.h"
#include "GameOverScene.h"
#include "EndingScene.h"
#include "OptionScene.h"
#include "HelpScene.h"
#include "SceneTransition.h"

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

    //chuyen Scene tu Scene source => Scene dest
    void createSceneWithTransition(Scene* dest, TransitionEffect* transition) 
    { 
        destScene = dest;
        isTransitioning = true;

        SceneTransition::getInstance()->setTransition(pInstance->pCurrentScene, dest, transition);
    }

    //kiem tra xem transition finish chua
    void updateWithEffect()
    {
        if (isTransitioning)
        {
            if (SceneTransition::getInstance()->isFinishTransition())
            {
                this->pInstance->createScene(destScene);
                isTransitioning = false;
            }
        }
    }

    bool isSceneTransitioning()
    {
        return isTransitioning;
    }

	Scene* getCurrentScene() { return pCurrentScene ;}
private:
	SceneManager() 
	{
		pCurrentScene = NULL;
        isTransitioning = false;
	}
	static SceneManager* pInstance;
	Scene* pCurrentScene;
    Scene* destScene; //dung do transition
    bool isTransitioning;
};
