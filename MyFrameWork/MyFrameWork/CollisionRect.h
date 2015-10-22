#pragma once
#include "Rect.h"

template <class T>
class CollisionRect
{
public:
	Rect<T> rect;
	std:: string type;
	float vx;
	float vy;

	CollisionRect() 
	{
		rect.x = (T)0;
		rect.y = (T)0;
		rect.width = (T)0;
		rect.height = (T)0;
		type = "";
		vx = 0.0f;
		vy = 0.0f;
	}
	CollisionRect( Rect<T> rect, std::string type, float vx = 0.0f, float vy = 0.0f)
		:
		rect(rect),
		type(type),
		vx(vx),
		vy(vy)
	{
		
	}
	/*bool operator == (const CollisionRect& cRect1, const CollisionRect& cRect2 )
	{
		return (cRect1.rect == cRect2.rect && cRect1.type == cRect2.type);
	}*/
	bool operator == ( const CollisionRect& cRect2 )
	{
		return (this -> rect == cRect2.rect && this -> type == cRect2.type);
	}
	
	void zero()
	{
		rect.x = (T)0;
		rect.y = (T)0;
		rect.width = (T)0;
		rect.height = (T)0;
		type = "";
	}
};

typedef CollisionRect<float> CollisionRectF;