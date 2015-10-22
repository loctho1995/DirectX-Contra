#pragma once
#include "Sprite.h"
#include "ObjectData.h"
class ObjectSprite : public Sprite
{
public:
	ObjectSprite(void);
	virtual ~ ObjectSprite(void);

	//EnermySprite(std::string mapName){}

	virtual RectF getBody() { return pData ->getBody(); }
	virtual CollisionRectF getCollisionRect() { return CollisionRectF(getBody(),"throughable", pData ->vx, pData -> vy); }
	virtual void setBody(RectF r ) { pData ->body =  r;} 
	/*virtual RectF getLastFrameBody() {return pData ->getLastFrameBody();}*/
	virtual float getVx() {return pData -> vx;} 
	virtual float getVy() {return pData -> vy;}
	virtual void onUnsupported() { pData -> pState -> onFall();}
	virtual void setPlayerX(int x) {pData ->playerX = x;}
	virtual void setPlayerY( int y ) {pData ->playerY = y;}
	virtual void onCollision(RectF r)	{ pData ->pState ->onCollision(r); }
    virtual SpriteState* getState(){ return this->pData->pState; } //phai them doan doan nay de goi pData cua EnermySprite chu ko phai thang cha
    virtual void initTextureArrays(int count)
    {
        pData->ppTextureArrays = new TextureArray * [count];
    }



	virtual void update() 
    {
        pData->pState->onUpdate();
    }

    virtual void draw(Camera *cam)
    {
        if (pData->dir.isRight())
            pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
        else if (pData->dir.isLeft())
            pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
    }
	
	virtual void onUpdate() {}

	virtual void die() { pData ->pState -> onDead();}
	virtual bool isDesTroyed() { return pData ->isDesTroyed;}
	virtual bool isHittable() {return pData -> isHittable;}

	virtual std::string getName() {return pData ->objectName;} 



	virtual void beShooted( int damage) 
	{
		pData -> HP -= damage;
		if( pData -> HP <= 0 )
		{
			die();
		}
	}

	virtual bool isPlayerCollisionable()
	{
		return pData ->isPlayerCollisionable;
	}
	virtual bool isEnemyCollisionable()
	{
		return pData -> isEnemyCollisionable;
	}
	virtual bool isAffectble()
	{
		return pData -> isAffectble;
	} 
protected:
	ObjectData* pData;
};

