#pragma once
#include "TextureArray.h"
#include "Direction.h"
#include "CollisionRect.h"

class SpriteData
{
public:
	SpriteData()
	{
		isDesTroyed = false;
		isHittable = true;
	}
	RectF getBody()
	{
		RectF r;
		r = body;
		r.translate(x, y);        
		return r;
	}
	/*RectF getLastFrameBody()
	{
		RectF r;
		r = body;
		r.translate(lx, ly);
		return r;
	}*/
	
	
public:
	float transform( float val)
	{
		if ( dir.isLeft()  )
		{
			return val * -1;
		}
		else if( dir.isRight()  )
			return val;
		else return 0;
	}
	float verticalTransform( float val)
	{
		if ( verticalDir.isUp()  )
		{
			return val * -1;
		}
		else if( verticalDir.isDown()  )
			return val;
		else return 0;
	}
	TextureArray ** ppTextureArrays;
	unsigned int iCurrentArr;
	float x;
	float y; 
	//float lx; // last frame x
	//float ly; // last frame y
	float vx;
	float vy;
	Direction dir;
	Direction verticalDir;
	RectF body;
	CollisionRectF cSupportRect;
	CollisionRectF* cDynamicSupportRect;
	std::vector< CollisionRectF > cThroughRect;
	std::vector< CollisionRectF* > dynamicThroughRect;
	class SpriteState* pState;
	bool isDesTroyed;
	bool isHittable;
	bool isDead;
};