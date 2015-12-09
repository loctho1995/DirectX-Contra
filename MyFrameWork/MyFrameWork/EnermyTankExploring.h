#include"EnermyState.h"

class EnermyTankExploring : public EnermyState
{
public: 
	EnermyTankExploring(EnermyData *pData, int index);
	~EnermyTankExploring();

	void onUpdate();
private:
	int index;
};