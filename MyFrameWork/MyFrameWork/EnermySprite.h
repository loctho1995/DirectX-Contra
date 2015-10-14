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
	virtual void setPlayerX(int x) {pData ->playerX = x;}
	virtual void setPlayerY( int y ) {pData ->playerY = y;}
	virtual void onCollision(RectF r)	{ pData ->pState ->onCollision(r); }
	virtual void onUpdate() {}
	virtual std::vector< BulletSprite* >& getBullets() { return pData -> Bullets;}
	virtual void die() { pData ->pState -> onDead();}
	virtual bool isDesTroyed() { return pData ->isDesTroyed;}
	virtual bool isHittable() {return pData -> isHittable;}
	virtual std::string getName() {return pData ->name;} 
	virtual void beShooted( int damage) 
	{
		pData -> HP -= damage;
		if( pData -> HP <= 0 )
		{
			die();
		}
	}
protected:
	EnermyData* pData;
};