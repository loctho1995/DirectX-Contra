#pragma once
#include "TextureArray.h"
#include "SpriteData.h"
#include "SpriteState.h"
class Sprite
{
public:
	Sprite() 
	{
		pData = new SpriteData();
	}
	virtual ~Sprite() {}
	virtual void draw(Camera* cam) = 0 ;
	virtual void update() = 0;  
	virtual SpriteState* getState()
	{
		return pData -> pState;
	}
	virtual RectF getBody() { return pData ->getBody(); }
	virtual void setBody(RectF r ) { pData ->body =  r;} 
	/*virtual RectF getLastFrameBody() {return pData ->getLastFrameBody();}*/
	virtual float getVx() {return pData -> vx;} 
	virtual float getVy() {return pData -> vy;}
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

	virtual void setSupportCollisionRect(CollisionRectF* rect)
	{
		pData ->cDynamicSupportRect = rect;
	}

	virtual std::vector< CollisionRectF >&  getThroughRect()
	{
		return pData ->cThroughRect;
	}
	virtual std::vector< CollisionRectF* >&  getDynamicThroughRect()
	{
		return pData ->dynamicThroughRect;
	}
	virtual void updateThroughRect()
	{
		for (int i = 0; i < pData->cThroughRect.size(); i++)
		{
			if(!pData ->getBody().checkCollision( pData ->cThroughRect[i].rect))
			{
				pData->cThroughRect.erase( pData->cThroughRect.begin() + i );
			}
		}

		for (int i = 0; i < pData -> dynamicThroughRect.size(); i++)
		{
			if(pData -> dynamicThroughRect[i] || !pData ->getBody().checkCollision( pData ->dynamicThroughRect[i] ->rect))
			{
				pData -> dynamicThroughRect.erase( pData->dynamicThroughRect.begin() + i );
			}
		}
	}
	virtual void die() {}
	virtual bool isDesTroyed() { return pData ->isDesTroyed;}
	virtual bool isHittable() {return pData -> isHittable;}
	virtual void onCameraCollision(RectF cameraRect) 
	{
		if( !pData -> getBody ().checkCollision(cameraRect) )
			pData -> isDesTroyed = true;
	}
	virtual bool isDead()
	{
		return pData -> isDead;
	}
protected:
	SpriteData* pData;
};