#include "SceneTransition.h"

SceneTransition* SceneTransition::instance = nullptr;

SceneTransition::SceneTransition()
{
}

SceneTransition::~SceneTransition()
{
}

SceneTransition* SceneTransition::getInstance()
{
    if (SceneTransition::instance == nullptr)
    {
        SceneTransition::instance = new SceneTransition();
        SceneTransition::instance->transition = nullptr;
    }

    return SceneTransition::instance;
}

void SceneTransition::update()
{
    if (this->instance->transition != nullptr)
    {
        this->instance->transition->update();
    }
}

bool SceneTransition::isFinishTransition()
{
    if (this->instance->transition != nullptr)
    {
        return this->instance->transition->isFinish();
    }
}

void SceneTransition::setTransition(Scene* source, Scene* dest, TransitionEffect* transition)
{
    this->instance->transition = transition;
    this->instance->transition->setScenes(source, dest);
}

