#pragma once
#include "ObjectStaticWeaponData.h"
#include "ObjectStaticWeaponCloseState.h"
#include "ObjectStaticWeaponOpenState.h"
#include "ObjectStaticWeaponOutState.h"
#include "ObjectStaticWeaponPreparingState.h"
#include "ObjectStaticWeaponOutState.h"
#include "ObjectSprite.h"

class ObjectStaticWeapon : public ObjectSprite
{
public:
    ObjectStaticWeapon(float x, float y);
    ~ObjectStaticWeapon();

    void beShooted(int damage);
};

