#include"EnermyState.h"

class EnermyScubarSoliderHidingState : public EnermyState
{
public:
	EnermyScubarSoliderHidingState(EnermyData *pData, bool isFirst = false);
	~EnermyScubarSoliderHidingState();
	void onUpdate();
private:
	int iFrame;
	bool isFirst;
};