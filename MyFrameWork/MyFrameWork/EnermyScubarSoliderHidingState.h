#include"EnermyState.h"

class EnermyScubarSoliderHidingState : public EnermyState
{
public:
	EnermyScubarSoliderHidingState(EnermyData *pData);
	~EnermyScubarSoliderHidingState();
	void onUpdate();
private:
	int iFrame;
};