#include"EnermyState.h"
#define PI 3.14

class EnermyTankShootingState : public EnermyState
{
public:
	EnermyTankShootingState(EnermyData *pData, int index);
	~EnermyTankShootingState();
	void onUpdate();

private:
	int iFrames;
	int index;
	int count;
	int iLastIndex;
	void Shoot();
	void getSprite();
	float directPlayerX, directPlayerY;
};