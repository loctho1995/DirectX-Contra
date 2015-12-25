#include "ViewPort.h"

ViewPort :: ViewPort(RectI port)
	:
	port(port)
{}

int ViewPort :: getWidth()
{
	return port.width;
}
int ViewPort ::getHeight() 
{
	return port.height;
}
