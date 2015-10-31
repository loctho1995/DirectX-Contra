#include"EnermyState.h"
#include"EnermyGunRotatingData.h"
#define PI 3.14

class EnermyGunRotatingDieState :public EnermyState
{
public:
	EnermyGunRotatingDieState(EnermyData *pData);
	~EnermyGunRotatingDieState();

	void onUpdate();
private:
	int iFrame;
};