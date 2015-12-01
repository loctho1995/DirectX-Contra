#pragma once
#include "ObjectStaticWeaponData.h"
#include "ObjectStaticWeaponCloseState.h"
#include "ObjectStaticWeaponOpenState.h"
#include "ObjectStaticWeaponOutState.h"
#include "ObjectStaticWeaponPreparingState.h"
#include "ObjectStaticWeaponOutState.h"
#include "ObjectSprite.h"
#include "Define.h"

class ObjectStaticWeapon : public ObjectSprite
{
public:
    ObjectStaticWeapon(float x, float y, BulletTypes bulletType);
    ~ObjectStaticWeapon();

    void beShooted(int damage);
    BulletTypes getBulletType();
	void die();

    void onCameraCollision(RectF rect);
    static void loadResources();
};

