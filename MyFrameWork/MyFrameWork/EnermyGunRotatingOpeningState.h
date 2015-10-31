#include"EnermyState.h"
#include"EnermyGunRotatingData.h"

class EnermyGunRotatingOpeningState :public EnermyState
{
public:
	EnermyGunRotatingOpeningState(EnermyData *pData);
	~EnermyGunRotatingOpeningState();

	void onUpdate();
private:
	int iFrame;
};