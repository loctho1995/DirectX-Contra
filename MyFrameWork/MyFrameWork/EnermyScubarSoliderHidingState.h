#include"EnermyState.h"

class EnermyScubarSoliderHidingState : public EnermyState
{
public:
	EnermyScubarSoliderHidingState(EnermyData *pData, bool isFirst = false);
	~EnermyScubarSoliderHidingState();
	void onUpdate();
	virtual void onDead();
private:
	int iFrame;
	bool isFirst;
	float directPlayerY;
};