#include"EnermyState.h"
#include"EnermyGunRotatingData.h"
#define PI 3.14

class EnermyGunRotatingSwavelingState :public EnermyState
{
public:
	EnermyGunRotatingSwavelingState(EnermyData *pData);
	~EnermyGunRotatingSwavelingState();
	virtual void onDead();
	void onCameraCollision(RectF cameraRect);

	void onUpdate();
private:
	int iFrame;
	float fAngle;
	float getDistance();
	float getAngle();// goc hop voi phuong ngang voi nguoi choi
	float listAngle[12];//luu index tung hinh theo PI
	void setlistAngle();
	void SwavelingAndShoot(int,int, int);
	int getIndex();//lay index hinh xoay de ban
	int iCurentIndex;
	bool getDistanceToClose();
	int distanceX, distanceY; // distance de close forever
	int temp;// distance de co dinh trang close
	int index;
	bool isTheFirst;
	float directPlayerX, directPlayerY;
};