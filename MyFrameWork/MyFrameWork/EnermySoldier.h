#pragma once
#include "EnermySprite.h"
#include "EnermySoldierData.h"
#include "EnermySoldierRunningState.h"
#include "EnermySoldierJumpingState.h"
#include "EnermySoldierDestroyState.h"
#include "EnermySoldierDieState.h"
#include "Camera.h"
#include "PlayerSprite.h"
#include "EnermyWhiteBullet.h"

class EnermySoldier : public EnermySprite
{
public:
    EnermySoldier(float x, float y, Direction dir, bool isShoter = false, std::vector<BulletSprite*>& bullet = std::vector<BulletSprite*>());
    ~EnermySoldier();

    void setSupportCollisionRect(CollisionRectF rect);
    void onCameraCollision(RectF cameraRect);
    void die();
    static void loadResources();
    //void update();
    //void draw(Camera *cam);
};


