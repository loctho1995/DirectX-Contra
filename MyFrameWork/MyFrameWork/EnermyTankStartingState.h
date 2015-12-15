#include"EnermyState.h"
#include"EnermyTankData.h"

class EnermyTankStartingState :public EnermyState
{
public:
	EnermyTankStartingState(EnermyData *pData, int s);
	~EnermyTankStartingState();

	void onUpdate();

private:
	int iFrames;
	int s, s0; // quang duong di duoc
	void getSprite();

};