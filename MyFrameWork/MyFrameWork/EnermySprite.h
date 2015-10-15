#pragma once
#include "EnermyData.h"
#include "Sprite.h"
class EnermySprite : public Sprite
{
public:
	EnermySprite() {}
	//EnermySprite(std::string mapName){}
	virtual ~EnermySprite() {}
	virtual RectF getBody() { return pData ->getBody(); }
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

    //frames: so frame de chay texture ke tiep
    virtual void addTextureArray(int index, std::string stateName, unsigned int textures, unsigned int frames)
    {
        pData->ppTextureArrays[index] = new TextureArray("Resources\\Sprites", pData->botName, stateName, textures, frames);
        pData->ppTextureArrays[index]->setAnchorPoint(0.5f, 1.0f);
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
	virtual std::vector< BulletSprite* >& getBullets() { return pData -> Bullets;}
	virtual void die() { pData ->pState -> onDead();}
	virtual bool isDesTroyed() { return pData ->isDesTroyed;}
	virtual bool isHittable() {return pData -> isHittable;}
	virtual std::string getName() {return pData ->botName;} 
	virtual void beShooted( int damage) 
	{
		pData -> HP -= damage;
		if( pData -> HP <= 0 )
		{
			die();
		}
	}

protected:
	EnermyData* pData;
};