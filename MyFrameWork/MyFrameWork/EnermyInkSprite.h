#pragma once

#include "EnermySprite.h"
#include "EnermyInkStandingState.h"
class EnermyInkSprite : public EnermySprite
{
public:
	EnermyInkSprite(int respawnX, int respawnY);
	virtual void draw( Camera* cam) ;
	virtual void update();
	virtual void setPlayerX(int x) ;
	virtual void setPlayerY( int y ) ;
};