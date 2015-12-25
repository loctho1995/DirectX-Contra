#pragma once
#include "EnermyData.h"
#include "Sprite.h"
class EnermySprite : public Sprite
{
public:
	EnermySprite() 
	{
		pData = new EnermyData();
	}
	EnermySprite( std:: vector < BulletSprite* >& bulletsVector )
	{
		pData = new EnermyData(bulletsVector);
	}

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
	virtual void setPlayerProperties (float x, float y, bool isDead) 
	{
		pData -> playerX = x;
		pData -> playerY = y;
		pData -> isPlayerDead = isDead;
	}

	virtual void setPlayerProperties (float player1X, float player1Y, bool isplayer1Dead, float player2X, float player2Y , bool isplayer2Dead) 
	{
		pData -> playerX = player1X;
		pData -> playerY = player1Y;
		pData -> isPlayerDead = isplayer1Dead;

		pData -> player2X = player2X;
		pData -> player2Y = player2Y;
		pData -> isPlayer2Dead = isplayer2Dead;
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
	virtual void die() { pData ->pState -> onDead(); }
	virtual bool isDesTroyed() { return pData ->isDesTroyed;}
	virtual bool isHittable() {return pData -> isHittable;}
	virtual std::string getName() {return pData ->botName;} 
	virtual void setSupportCollisionRect(CollisionRectF rect)
	{
		pData ->cSupportRect = rect;
	}
	virtual std::vector< CollisionRectF >&  getThroughRect()
	{
		return pData ->cThroughRect;
	}
	virtual void updateThroughRect()
	{
		for (int i = 0; i < pData->cThroughRect.size(); i++)
		{
			if(!pData ->getBody().checkCollision( pData ->cThroughRect[i].rect))
			{
				pData->cThroughRect.erase( pData->cThroughRect.begin() + i );
			}
		}
	}
	virtual void beShooted( int damage, int playerIndex) 
	{
		playBeShootedEffect();
		pData -> HP -= damage;
		if( pData -> HP <= 0 )
		{
			pData -> isDead = true;
			pData -> killBy = playerIndex;
			die();
		}
	}
	virtual void playBeShootedEffect()
	{

	}
	virtual bool isThroughable()
	{
		return pData -> isThrougable;
	}
	virtual void onCameraCollision(RectF cameraRect) 
	{
		if( !pData -> getBody().checkCollision(cameraRect) )
			pData -> isDesTroyed = true;
	}
	virtual int getScore()
	{
		return pData -> score;
	}
	virtual bool isDead()
	{
		return pData -> isDead;
	}
	virtual Direction getAppearDir() 
	{
		return pData -> appearDir;
	}

	virtual int getKillByIndex()
	{
		return pData -> killBy;
	}
protected:
	EnermyData* pData;
};