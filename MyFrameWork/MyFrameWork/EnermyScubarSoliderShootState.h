#include"EnermyState.h"

class EnermyScubarSoliderShootState : public EnermyState
{
public:
	EnermyScubarSoliderShootState(EnermyData *pData);
	~EnermyScubarSoliderShootState();
	void onUpdate();
	virtual void onDead();

private:
	int iFrames;
	bool flag;
};