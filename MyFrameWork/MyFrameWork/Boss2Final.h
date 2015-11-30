#pragma once
#include "Boss2FinalJoint.h"

class Boss2Final
{
public:
    ~Boss2Final();

    static Boss2Final *getInstance();
    bool isLeftArmDie();
    bool isRightArmDie();
    void setLeftArmState(bool isDie);
    void setRightArmState(bool isDie);
    static void loadResources();

private:
    Boss2Final();
    static Boss2Final *instance;
    static bool leftArm, rightArm;
};

