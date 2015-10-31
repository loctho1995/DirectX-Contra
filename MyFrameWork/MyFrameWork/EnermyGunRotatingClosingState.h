#include"EnermyState.h"
#include"EnermyGunRotatingData.h"

class EnermyGunRotatingClosingState :public EnermyState
{
public:
	EnermyGunRotatingClosingState(EnermyData *pData);
	~EnermyGunRotatingClosingState();

	void onUpdate();
private:
	float iDistance;
	int iFrame;
};