#pragma once

#include "Rect.h"
#include "Graphics.h"

class ViewPort
{
public:
	ViewPort( RectI port);
	int getWidth();
	int getHeight();
	RectI getPort()	 {return port;} 
private:
	RectI port;
};