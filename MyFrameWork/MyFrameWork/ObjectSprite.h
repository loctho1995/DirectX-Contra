#pragma once
#include "Sprite.h"
#include "ObjectData.h"

class ObjectSprite : public Sprite
{
public:
	ObjectSprite();
	virtual ~ObjectSprite();

	//EnermySprite(std::string mapName){}

	virtual RectF getBody() { return pData ->getBody(); }
	virtual CollisionRectF getCollisionRect() { return CollisionRectF(getBody(),"throughable", this -> pData ->vx, this -> pData -> vy); }
	virtual CollisionRectF* getRefCollisionRect() {return &pData ->collisionRect;}
	virtual void setBody(RectF r ) { pData ->body =  r;} 
	/*virtual RectF getLastFrameBody() {return pData ->getLastFrameBody();}*/
	virtual float getVx() {return pData -> vx;} 
	virtual float getVy() {return pData -> vy;}
	virtual void onUnsupported() { pData -> pState -> onFall();}
	virtual void setPlayerProperties (float x, float y) 
	{
		pData -> playerX = x;
		pData -> playerY = y;
	}

	virtual void setPlayerProperties (float player1X, float player1Y, float player2X, float player2Y ) 
	{
		pData -> playerX = player1X;
		pData -> playerY = player1Y;
		pData -> player2X = player2X;
		pData -> player2Y = player2Y;
	} 
	virtual void onCollision(RectF r)	{ pData ->pState ->onCollision(r); }
	virtual void onCollision(CollisionRectF r)	{ pData ->pState ->onCollision(r); }
    virtual SpriteState* getState(){ return this->pData->pState; } //phai them doan doan nay de goi pData cua EnermySprite chu ko phai thang cha
    virtual void initTextureArrays(int count)
    {
        pData->ppTextureArrays = new TextureArray * [count];
    }

    //frames: so frame de chay texture ke tiep
    virtual void addTextureArray(int index, std::string stateName, unsigned int textures, unsigned int frames)
    {
        pData->ppTextureArrays[index] = new TextureArray("Resources\\Sprites", pData->objectName, stateName, textures, frames);
        pData->ppTextureArrays[index]->setAnchorPoint(0.5f, 1.0f);
    }

	virtual void update() 
    {
        pData->pState->onUpdate();
		pData -> collisionRect  = CollisionRectF(pData ->getBody(), "throughable", pData -> vx, pData -> vy);
    }

    virtual void draw(Camera *cam)
    {
        if (pData->dir.isRight())
            pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
        else if (pData->dir.isLeft())
            pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
    }
	
	virtual void onUpdate() {}

	virtual void die() { this ->pData ->pState -> onDead();}
	virtual bool isDesTroyed() { return pData ->isDesTroyed;}
	virtual bool isHittable() {return pData -> isHittable;}

	virtual std::string getName() {return pData ->objectName;} 
	virtual void onCameraCollision(RectF cameraRect) 
	{
		if( !this -> pData -> getBody ().checkCollision(cameraRect) )
			this -> pData -> isDesTroyed = true;
	}


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
	virtual Direction getAppearDir() 
	{
		return pData -> appearDir;
	}
protected:
	ObjectData* pData;
};

