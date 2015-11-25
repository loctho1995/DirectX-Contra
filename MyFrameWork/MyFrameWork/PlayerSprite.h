#pragma once
#include "PlayerState.h"

class PlayerSprite : public Sprite
{
public:
	PlayerSprite(float respawnX, float respawnY, Direction movedir);
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
	virtual void onDynamicObjectCollision(CollisionRectF* r)	{ pData ->pState ->onDynamicObjectCollision(r); }
	virtual void setSupportCollisionRect(CollisionRectF rect)
	{
		pData ->cSupportRect = rect;
	}
	virtual void setSupportCollisionRect(CollisionRectF* rect)
	{
		pData ->cDynamicSupportRect = rect;
	}

	virtual std::vector< CollisionRectF>& getThroughRect();
	virtual std::vector< CollisionRectF* >&  getDynamicThroughRect();
	virtual void updateThroughRect();
	std::vector<BulletSprite* >& getBullets();
	virtual void die();
	virtual void onCameraCollision(RectF cameraRect);
	virtual bool isDesTroyed() { return pData ->isDesTroyed;}
	virtual bool isHittable() {return pData -> isHittable;}
	virtual int getDamage();
	void setCameraRect(RectF r);
	void setBulletType (BulletTypes type)
	{
		if( type != BulletTypes::R && type != BulletTypes::B)
			pData -> bulletType = type;
		else if (type == BulletTypes::R)
		{
			pData -> isRapid = true;
		}
		else		
		{
			pData -> isUndying = true;
		}
	}
	
	static void loadResources();

	bool isDead()
	{
		return pData -> isDead;
	}
	bool isUndying()
	{
		return pData -> isUndying;
	}
	
private:
	PlayerData* pData;
};