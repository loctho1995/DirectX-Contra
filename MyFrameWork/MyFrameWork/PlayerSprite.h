#pragma once
#include "PlayerState.h"
class PlayerSprite : public Sprite
{
public:
	PlayerSprite();
	~PlayerSprite();
	virtual void update( );
	virtual void draw(Camera* cam);
	void setCameraTo(Camera* cam);
	virtual SpriteState* getState()
	{
		return pData -> pState;
	}
	virtual RectF getBody() { return pData ->getBody(); }
	virtual void setBody(RectF r ) { pData ->body =  r;} 
	/*virtual RectF getLastFrameBody() {return pData ->getLastFrameBody();}*/
	virtual float getVx() {return pData -> vx;} 
	virtual float getVy() {return pData -> vy;}
	virtual float getX() {return pData -> x; }
	virtual float getY() { return pData -> y;}
	virtual float getCenterX() {return pData -> x;}
	virtual float getCenterY() {return pData -> y - pData ->ppTextureArrays[ pData ->iCurrentArr ] -> getHeight() / 2;}
	virtual void onUnsupported() { pData -> pState -> onFall();}
	/*virtual void updateLastFrame() 
	{
		pData -> lx = pData -> x;
		pData -> ly = pData -> y;
	}*/
	virtual void onCollision(RectF r)	{ pData ->pState ->onCollision(r); }
	virtual void onCollision(CollisionRectF r)	{ pData ->pState ->onCollision(r); }
	virtual void setSupportCollisionRect(CollisionRectF rect)
	{
		pData ->cSupportRect = rect;
	}
	virtual std::vector< CollisionRectF>& getThroughRect();
	virtual void updateThroughRect();
	std::vector<BulletSprite* >& getBullets();
	virtual void die();
	virtual void onCameraCollision(RectF cameraRect);
	virtual void setCameraRect( RectF cameraRect);
	virtual bool isDesTroyed() { return pData ->isDesTroyed;}
	virtual bool isHittable() {return pData -> isHittable;}
	virtual int getDamage();
	
private:
	PlayerData* pData;
};