#include "Lighting.h"


Lighting::Lighting(void)
{
	position = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.0f);
	direction = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.0f);
	color = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.0f);
	cutOff  = 1;


}

Lighting:: Lighting(D3DXVECTOR4 position,
					D3DXVECTOR4 direction,
					float cutOff,
					D3DXVECTOR4 color)
	:
 position(position),
 direction(direction),
 cutOff(cutOff),
 color(color)
 {

 }


D3DXVECTOR4 Lighting:: getPosition()
{
	return position;
}
D3DXVECTOR4 Lighting::  getDirection()
{
	return direction;
}
float Lighting:: getCutOff()
{
	return cutOff;
}
D3DXVECTOR4 Lighting:: getColor()
{
	return color;
}
void Lighting:: setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}
void Lighting:: setDirection(D3DXVECTOR4 val)
{
	direction = val;
}
void Lighting:: setCutOff(float cutoff)
{
	cutOff = cutoff;
}
void Lighting:: setColor(D3DXVECTOR4 val)
{
	color = color;
}


Lighting::~Lighting(void)
{
}
