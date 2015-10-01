#pragma once
#include "EnermyData.h"
#include "Sprite.h"
class EnermySprite : public Sprite
{
public:
	EnermySprite() {}
	//EnermySprite(std::string mapName){}
	virtual ~EnermySprite() {}
	virtual RectF getBody() { return pData ->getBody(); }
	virtual void setBody(RectF r ) { pData ->body =  r;} 
	/*virtual RectF getLastFrameBody() {return pData ->getLastFrameBody();}*/
	virtual float getVx() {return pData -> vx;} 
	virtual float getVy() {return pData -> vy;}
	virtual void onUnsupported() { pData -> pState -> onFall();}
	virtual void setPlayerX(int x) {}
	virtual void setPlayerY( int y ) {}
	virtual void onCollision(RectF r)	{ pData ->pState ->onCollision(r); }
	virtual void onUpdate() {}
	
protected:
	EnermyData* pData;
};