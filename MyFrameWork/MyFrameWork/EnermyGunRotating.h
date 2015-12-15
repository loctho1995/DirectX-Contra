#include "EnermyGunRotatingClosingState.h"
#include "EnermySprite.h"
#include "PlayerSprite.h"
#include "Camera.h"
#define PI 3.4

class EnermyGunRotating :public EnermySprite
{
public:
	EnermyGunRotating(float x, float y, int isStage, std::vector < BulletSprite*>& bulletSpriteVector);
	~EnermyGunRotating();
	void update();
	void draw(Camera *cam);
	static void loadResources();
	virtual void playBeShootedEffect();

};