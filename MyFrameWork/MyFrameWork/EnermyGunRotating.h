#include"EnermyGunRotatingClosingState.h"
#include"EnermySprite.h"
#include"PlayerSprite.h"
#include"Camera.h"
#define PI 3.4

class EnermyGunRotating :public EnermySprite
{
public:
	EnermyGunRotating(float x, float y);
	~EnermyGunRotating();
	void update();
	void draw(Camera *cam);

};