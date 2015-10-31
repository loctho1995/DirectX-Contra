#include"EnermyState.h"
#include"EnermyGunRotatingData.h"
#define PI 3.14

class EnermyGunRotatingSwavelingState :public EnermyState
{
public:
	EnermyGunRotatingSwavelingState(EnermyData *pData);
	~EnermyGunRotatingSwavelingState();
	virtual void onDead();

	void onUpdate();
private:
	int iFrame;
	float fAngle;
	float getDistance();
	float getAngle();// goc hop voi phuong ngang voi nguoi choi
	float listAngle[12];//luu index tung hinh theo PI
	void setlistAngle();

	int getIndex();//lay index hinh xoay de ban
	int iCurentIndex;
	bool getDistanceToClose();
	int distance; // distance de close forever
	int temp;// distance de co dinh trang close
};