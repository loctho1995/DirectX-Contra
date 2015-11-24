#include"EnermyState.h"

class EnermyScubarSoliderShootState : public EnermyState
{
public:
	EnermyScubarSoliderShootState(EnermyData *pData);
	~EnermyScubarSoliderShootState();
	void onUpdate();
private:
	int iFrames;
	bool flag;
};