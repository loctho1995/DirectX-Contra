#pragma once
#include "TextureArray.h"
#include "Direction.h"
#include "CollisionRect.h"

class SpriteData
{
public:
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
	SpriteData()	
	{
	}
	float transform( float val)
	{
		if ( dir.isLeft() || dir.isUp() )
		{
			return val * -1;
		}
		else if( dir.isRight() || dir.isDown() )
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
	std::vector< CollisionRectF > cThroughRect;
	class SpriteState* pState;
};