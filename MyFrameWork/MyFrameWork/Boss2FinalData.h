#pragma once
#include "Boss2FinalJoint.h"
#include "Boss2FinalHand.h"
#include "BulletSprite.h"
#include "EnermyData.h"

class Boss2FinalData : public EnermyData
{
public:
    enum ArmSide
    {
        LEFT,
        RIGHT
    };

    enum ArrayIndex
    {
        SHUT,
        OPEN,
        DIE,
        COUNT
    };

    Boss2FinalData(std::vector < BulletSprite* >& bulletsVector = std::vector <BulletSprite* >());
    ~Boss2FinalData();

    Boss2FinalJoint* joints[5];
    float armLength;
    ArmSide armSide;
};

