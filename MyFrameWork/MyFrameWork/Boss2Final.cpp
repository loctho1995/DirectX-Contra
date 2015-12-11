#include "Boss2Final.h"

Boss2Final *Boss2Final::instance = nullptr;
bool Boss2Final::leftArm = false;
bool Boss2Final::rightArm = false;

Boss2Final::Boss2Final()
{

}


Boss2Final::~Boss2Final()
{
}

Boss2Final* Boss2Final::getInstance()
{
    if (!instance)
    {
        instance = new Boss2Final();
    }

    return instance;
}

bool Boss2Final::isLeftArmDie()
{
    return leftArm;
}

bool Boss2Final::isRightArmDie()
{
    return rightArm;
}

void Boss2Final::setLeftArmState(bool isDie)
{
    leftArm = isDie;
}

void Boss2Final::setRightArmState(bool isDie)
{
    rightArm = isDie;
}

void Boss2Final::loadResources()
{
    TextureArray *temp = new TextureArray("Resources\\Sprites", "boss2final", "joint", 1, 1);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "boss2final", "hand", 1, 1);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "boss2final", "headshut", 3, 15);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "boss2final", "head", 5, 15);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "boss2final", "body", 1, 15);
    delete temp;
}