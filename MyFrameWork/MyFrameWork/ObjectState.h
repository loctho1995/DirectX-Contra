#pragma once
#include "SpriteState.h"
#include "ObjectData.h"
class ObjectState : public SpriteState
{
public:
	ObjectState(void);
	virtual ~ObjectState(void);
    virtual void onUpdate() ;
	virtual void transition(SpriteState* state);
	
protected:
	ObjectData* pData;
};

