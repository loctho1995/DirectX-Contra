#pragma once
#include "Boss2FinalData.h"
#include "EnermySprite.h"
#include "Boss2FinalHeadShuttingState.h"
#include "BulletSprite.h"
#include "Boss2Final.h"
#include "Boss2FinalExplosionSprite.h"
#include "Boss2FinalBody.h"

class Boss2FinalHead : public EnermySprite
{
public:
    Boss2FinalHead(float x, float y, std::vector<BulletSprite*>& bulletSprite);
    ~Boss2FinalHead();

    void update();
    void draw(Camera *cam);
    void die();
    void onCameraCollision(RectF rect);

private:
    Boss2FinalExplosionSprite *explosion;
    Boss2FinalBody *bodySprite;
};

