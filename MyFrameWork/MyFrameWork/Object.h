#pragma once
#include "CollisionRect.h"

class Object
{
public:
	Object ( std::string name, std::string type, int x, int y, int id, int width, int height, RectF body)
		:
		name(name),
		type(type),
		x(x),
		y(y),
		id(id),
		width(width),
		height(height),
		body(body)
	{
	}
	int x;
	int y;
	int width;
	int height;
	int id;
	std::string name;
	RectF body;
	std::string type;
};