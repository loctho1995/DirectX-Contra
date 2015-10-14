#pragma once

#include "SpriteState.h"
#include "EnermyData.h"

class EnermyState : public SpriteState
{
public:
    EnermyState() {}

    virtual void onUpdate() 
    {
        pData->ppTextureArrays[pData->iCurrentArr]->update(); //fixed
    }

	virtual void transition(SpriteState* state)
	{
		pData -> pState = state; 
		delete this;
	}

	virtual void onCollision() {}
protected:
	EnermyData* pData;
};