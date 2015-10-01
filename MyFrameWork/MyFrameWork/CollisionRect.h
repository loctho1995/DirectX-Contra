#pragma once
#include "Rect.h"

template <class T>
class CollisionRect
{
public:
	Rect<T> rect;
	std:: string type;

	CollisionRect() 
	{
		rect.x = (T)0;
		rect.y = (T)0;
		rect.width = (T)0;
		rect.height = (T)0;
		type = "";
	}
	CollisionRect( Rect<T> rect, std::string type)
		:
		rect(rect),
		type(type)
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