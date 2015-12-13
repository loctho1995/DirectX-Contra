#pragma once
#include "TransitionEffect.h"
#include "Scene.h"

class SceneTransition
{
public:
    static SceneTransition* getInstance();

    void update();
    void setTransition(Scene* source, Scene* dest, TransitionEffect* transition);    
    bool isFinishTransition();
    Scene* sourceScene;

private:
    SceneTransition();
    ~SceneTransition();

    static SceneTransition* instance;

    TransitionEffect* transition;
};

