#include "PlayerSprite.h"
#include "PlayerJumpingState.h"
#include "Loader.h"
PlayerSprite::PlayerSprite(int index, float respawnX, float respawnY, Direction movedir)
{

	// Set up PlayerData
	pData = new PlayerData();

	pData -> index = index;

	pData -> bodyRects = new RectF [PlayerData::COUNT];

	pData->x  = respawnX;

	pData->y  = respawnY;

	pData ->movedir = movedir;

	pData -> ppTextureArrays = new TextureArray* [PlayerData::COUNT];

	std:: string spriteName = "";
	if(index == 1)
	{
		spriteName = std::to_string(2);
	}

	pData->ppTextureArrays[PlayerData:: STAND ] = new TextureArray("Resources\\Sprites", "player" + spriteName, "stand", 1, 60  ); 

	pData->ppTextureArrays[PlayerData:: STAND ] -> setAnchorPoint(0.5f, 1.0f );

	pData -> bodyRects[PlayerData:: STAND] = RectF(-14.0f / 2 - 3.0f, -32.0f, 14.0f, 32.0f);


	pData->ppTextureArrays[PlayerData:: STANDUP ] = new TextureArray("Resources\\Sprites", "player" + spriteName, "standup", 1, 60  ); 

	pData->ppTextureArrays[PlayerData:: STANDUP ] -> setAnchorPoint(0.5f, 1.0f );

	pData -> bodyRects[PlayerData:: STANDUP] = RectF(-14.0f / 2 , -32.0f, 14.0f, 32.0f);


	pData->ppTextureArrays[PlayerData:: STANDUPNFIRE ] = new TextureArray("Resources\\Sprites", "player" + spriteName, "standupnfire", 1, 60  ); 

	pData->ppTextureArrays[PlayerData:: STANDUPNFIRE ] -> setAnchorPoint(0.5f, 1.0f );

	pData -> bodyRects[PlayerData:: STANDUPNFIRE] = RectF(-14.0f / 2 - 3.0f, -32.0f, 14.0f, 32.0f);


	pData->ppTextureArrays[PlayerData:: STANDDOWN ] = new TextureArray("Resources\\Sprites", "player" + spriteName, "standdown", 1, 60  ); 
	pData->ppTextureArrays[PlayerData:: STANDDOWN ] -> setAnchorPoint(0.5f, 1.0f );
	pData -> bodyRects[PlayerData:: STANDDOWN] = RectF(-27.0f / 2, -12.0f, 27.0f, 12.0f);


	pData->ppTextureArrays[PlayerData:: STANDDOWNNFIRE ] = new TextureArray("Resources\\Sprites", "player" + spriteName, "standdownnfire", 1, 60  ); 
	pData->ppTextureArrays[PlayerData:: STANDDOWNNFIRE ] -> setAnchorPoint(0.5f, 1.0f );
	pData -> bodyRects[PlayerData:: STANDDOWNNFIRE] = RectF(-27.0f / 2, -12.0f, 27.0f, 12.0f);


	pData->ppTextureArrays[PlayerData:: STANDNFIRE ] = new TextureArray("Resources\\Sprites", "player" + spriteName, "standnfire", 1, 60  ); 
	pData->ppTextureArrays[PlayerData:: STANDNFIRE ] -> setAnchorPoint(0.5f, 1.0f );
	pData -> bodyRects[PlayerData:: STANDNFIRE] = RectF(-14.0f / 2 - 3.0f, -32.0f, 14.0f, 32.0f);


	pData->ppTextureArrays[PlayerData:: RUN ] = new TextureArray("Resources\\Sprites", "player" + spriteName, "run", 6, 8  ); 
	pData->ppTextureArrays[PlayerData:: RUN ] -> setAnchorPoint(0.5f, 1.0f );
	pData -> bodyRects[PlayerData:: RUN] = RectF(-12.0f / 2 , -32.0f, 12.0f, 32.0f);

	pData->ppTextureArrays[PlayerData::RUNNFIRE] = new TextureArray("Resources\\Sprites", "player" + spriteName, "runnfire", 6, 8);
	pData->ppTextureArrays[PlayerData:: RUNNFIRE ] -> setAnchorPoint(0.5f, 1.0f );
	pData -> bodyRects[PlayerData:: RUNNFIRE] = RectF(-12.0f / 2 , -32.0f, 12.0f, 32.0f);

	pData->ppTextureArrays[PlayerData:: RUNDOWN ] = new TextureArray("Resources\\Sprites", "player" + spriteName, "rundown", 3, 8);
	pData->ppTextureArrays[PlayerData:: RUNDOWN ] -> setAnchorPoint(0.5f, 1.0f );
	pData -> bodyRects[PlayerData:: RUNDOWN] = RectF(-12.0f / 2 , -32.0f, 12.0f, 32.0f);

	pData->ppTextureArrays[PlayerData:: RUNUP ] = new TextureArray("Resources\\Sprites", "player" + spriteName, "runup", 3, 8);
	pData->ppTextureArrays[PlayerData:: RUNUP ] -> setAnchorPoint(0.5f, 1.0f );
	pData -> bodyRects[PlayerData:: RUNUP] = RectF(-12.0f / 2 , -32.0f, 12.0f, 32.0f);


	pData->ppTextureArrays[PlayerData:: JUMP ] = new TextureArray("Resources\\Sprites", "player" + spriteName, "jump", 4, 4); 
	pData->ppTextureArrays[PlayerData:: JUMP ] -> setAnchorPoint(0.5f, 1.0f );
	pData -> bodyRects[PlayerData:: JUMP] = RectF(-12.0f / 2 , -32.0f, 12.0f, 32.0f);


	pData->ppTextureArrays[PlayerData:: FALL ] = new TextureArray("Resources\\Sprites", "player" + spriteName, "fall", 1, 60); 
	pData->ppTextureArrays[PlayerData:: FALL ] -> setAnchorPoint(0.5f, 1.0f );
	pData -> bodyRects[PlayerData:: FALL] = RectF(-12.0f / 2 , -32.0f, 12.0f, 32.0f);

	pData->ppTextureArrays[PlayerData:: DIVE ] = new TextureArray("Resources\\Sprites", "player" + spriteName, "dive", 2, 14  ); 
	pData->ppTextureArrays[PlayerData:: DIVE ] -> setAnchorPoint(0.5f, 1.0f );
	pData -> bodyRects[PlayerData:: DIVE] = RectF(-12.0f / 2 , -15.0f, 12.0f, 15.0f);


	pData->ppTextureArrays[PlayerData:: DIVEUP ] = new TextureArray("Resources\\Sprites", "player", "diveup", 2, 14  ); 
	pData->ppTextureArrays[PlayerData:: DIVEUP ] -> setAnchorPoint(0.5f, 1.0f );
	pData -> bodyRects[PlayerData:: DIVEUP] = RectF(-13.0f / 2 , -17.0f, 13.0f, 17.0f);

	pData->ppTextureArrays[PlayerData:: DIVEDOWN ] = new TextureArray("Resources\\Sprites", "player" + spriteName, "divedown", 1, 60  ); 
	pData->ppTextureArrays[PlayerData:: DIVEDOWN ] -> setAnchorPoint(0.5f, 1.0f );
	pData -> bodyRects[PlayerData:: DIVEDOWN] = RectF(-16.0f / 2 , -7.0f, 16.0f, 7.0f);

	pData->ppTextureArrays[PlayerData:: DIVENFIRE ] = new TextureArray("Resources\\Sprites", "player" + spriteName, "divenfire", 2, 14  ); 
	pData->ppTextureArrays[PlayerData:: DIVENFIRE ] -> setAnchorPoint(0.5f, 1.0f );
	pData -> bodyRects[PlayerData:: DIVENFIRE] = RectF(-19.0f / 2 , -15.0f, 19.0f, 15.0f);

	pData->ppTextureArrays[PlayerData:: SWIMUP ] = new TextureArray("Resources\\Sprites", "player" + spriteName, "swimup", 2, 14 );
	pData->ppTextureArrays[PlayerData:: SWIMUP ] -> setAnchorPoint(0.5f, 1.0f );
	pData -> bodyRects[PlayerData:: SWIMUP] = RectF(-15.0f / 2 , -16.0f - 2.0f, 15.0f, 16.0f);

	pData->ppTextureArrays[PlayerData:: CLIMP ] = new TextureArray("Resources\\Sprites", "player" + spriteName, "climb", 1, 60  ); 
	pData->ppTextureArrays[PlayerData:: CLIMP ] -> setAnchorPoint(0.5f, 1.0f );
	pData -> bodyRects[PlayerData:: CLIMP] = RectF(-15.0f / 2 , -11.0f, 15.0f, 11.0f);

	pData->ppTextureArrays[PlayerData:: DEAD ] = new TextureArray("Resources\\Sprites", "player" + spriteName, "dead", 4, 10 ); 
	pData->ppTextureArrays[PlayerData:: DEAD ] -> setAnchorPoint(0.5f, 1.0f );
	pData -> bodyRects[PlayerData:: DEAD] = RectF(-16.0f / 2 , -18.0f, 16.0f, 18.0f);

	pData->ppTextureArrays[PlayerData:: LIE ] = new TextureArray("Resources\\Sprites", "player" + spriteName, "lie", 1, 60 );
	pData->ppTextureArrays[PlayerData:: LIE ] -> setAnchorPoint(0.5f, 1.0f );
	pData -> bodyRects[PlayerData:: LIE] = RectF(-30.0f / 2 , -10.0f, 30.0f, 10.0f);



	pData ->dir = Direction::createRight();

	pData ->verticalDir = Direction ::createNone();
	
	pData ->bulletType = BulletTypes::S;

	pData ->pState = new PlayerJumpingState(pData, false, 0.0f);	

}

PlayerSprite:: ~PlayerSprite()
{
	for (int i = 0; i < PlayerData::COUNT; i++)
	{
		if(pData -> ppTextureArrays[i] )
			delete pData -> ppTextureArrays[i];
	}
	delete[] pData->ppTextureArrays;
	delete pData->bodyRects;
}

void PlayerSprite::draw(Camera* cam)
{
	int isDraw  = 0;
	if( pData ->isRespawn)
	{
		isDraw = rand()% 2;
	}
	if (isDraw == 0)
	{
		isDraw = rand()% 2;
		if(pData -> isUndying && isDraw == 0)
		{

			if( pData -> dir.isRight())
			pData->ppTextureArrays[ pData->iCurrentArr ] -> draw(pData -> x, pData -> y , cam , 1.0f,1.0f, D3DCOLOR_ARGB(255 ,255 , 0 , 60));
			else if( pData -> dir.isLeft())
			pData->ppTextureArrays[ pData->iCurrentArr ] -> drawFlipX(pData -> x, pData -> y , cam, 1.0f, 1.0f,D3DCOLOR_ARGB(255 , 255 , 0 ,60));
		}
		else
		{
			if( pData -> dir.isRight())
			pData->ppTextureArrays[ pData->iCurrentArr ] -> draw(pData -> x, pData -> y , cam);
			else if( pData -> dir.isLeft())
			pData->ppTextureArrays[ pData->iCurrentArr ] -> drawFlipX(pData -> x, pData -> y , cam);
		}
		
	}
	for (int i = 0; i < pData ->Bullets.size(); i++)
	{
		pData ->Bullets[i] ->draw(cam);
	}
	
}

void PlayerSprite::update( )
{
	pData -> pState -> onUpdate();
	for (int i = 0; i < pData ->Bullets.size(); i++)
	{
		pData ->Bullets[i] ->update();
	}
}


void PlayerSprite :: setCameraTo(Camera* cam)
{
	cam ->setPosition( pData->x, pData-> y );
}

std::vector<BulletSprite* >&  PlayerSprite :: getBullets()
{
	return pData -> Bullets;
}

std::vector< CollisionRectF>& PlayerSprite :: getThroughRect()
{
	return pData ->cThroughRect;
}
std::vector< CollisionRectF* >&  PlayerSprite :: getDynamicThroughRect()
{
	return pData ->dynamicThroughRect;
}
void PlayerSprite :: updateThroughRect()
{
	for (int i = 0; i < pData->cThroughRect.size(); i++)
		{
			if(!pData ->getBody().checkCollision( pData ->cThroughRect[i].rect))
			{
				pData->cThroughRect.erase( pData->cThroughRect.begin() + i );
			}
		}

		for (int i = 0; i < pData -> dynamicThroughRect.size(); i++)
		{
			if(!pData -> dynamicThroughRect[i] || !pData ->getBody().checkCollision( pData ->dynamicThroughRect[i] ->rect))
			{
				pData -> dynamicThroughRect.erase( pData->dynamicThroughRect.begin() + i );
			}
		}
}

void  PlayerSprite :: die()
{
	pData ->pState ->onDead();
}

void PlayerSprite :: onCameraCollision(RectF cameraRect)
{
	pData -> pState -> onCameraCollision(cameraRect);
}
void PlayerSprite ::  setCameraRect( RectF cameraRect)
{
	pData ->cameraRect = cameraRect;
}

int PlayerSprite ::  getDamage()
{
	
	switch (pData ->bulletType)
	{
	case BulletTypes::F:
		return 1;
	case BulletTypes::L:
		return 4;	
	case BulletTypes::M:
		return 1;
	case BulletTypes::S:
		return 1;
	default:
		return 1;
	}
}


void PlayerSprite :: loadResources()
{


	TextureArray* temp = new TextureArray("Resources\\Sprites", "player", "stand", 1, 60  ); 

	delete temp;

	temp = new TextureArray("Resources\\Sprites", "player", "standup", 1, 60  ); 

	delete temp;

	temp = new TextureArray("Resources\\Sprites", "player", "standupnfire", 1, 60  ); 

	delete temp;

	temp = new TextureArray("Resources\\Sprites", "player", "standdown", 1, 60  ); 

	delete temp;

	temp = new TextureArray("Resources\\Sprites", "player", "standdownnfire", 1, 60  ); 

	delete temp;


	temp = new TextureArray("Resources\\Sprites", "player", "standnfire", 1, 60  ); 

	delete temp;

	temp = new TextureArray("Resources\\Sprites", "player", "run", 6, 8  ); 

	delete temp;

	temp = new TextureArray("Resources\\Sprites", "player", "runnfire", 6, 8);

	delete temp;

	temp = new TextureArray("Resources\\Sprites", "player", "rundown", 3, 8);

	delete temp;

	temp = new TextureArray("Resources\\Sprites", "player", "runup", 3, 8);

	delete temp;

	temp = new TextureArray("Resources\\Sprites", "player", "jump", 4, 4); 

	delete temp;


	temp = new TextureArray("Resources\\Sprites", "player", "fall", 1, 60); 

	delete temp;

	temp = new TextureArray("Resources\\Sprites", "player", "dive", 2, 14  ); 

	delete temp;

	temp = new TextureArray("Resources\\Sprites", "player", "diveup", 2, 14  ); 

	delete temp;

	temp = new TextureArray("Resources\\Sprites", "player", "divedown", 1, 60  ); 

	delete temp;

	temp = new TextureArray("Resources\\Sprites", "player", "divenfire", 2, 14  ); 

	delete temp;

	temp = new TextureArray("Resources\\Sprites", "player", "swimup", 2, 14 );

	delete temp;

	temp = new TextureArray("Resources\\Sprites", "player", "climb", 1, 60  ); 

	delete temp;

	temp = new TextureArray("Resources\\Sprites", "player", "dead", 4, 10 ); 

	delete temp;

	temp = new TextureArray("Resources\\Sprites", "player", "lie", 1, 60 );

	delete temp;


	// bullet


	temp = new TextureArray("Resources\\Sprites\\Bullets", "mbullet","", 1, 60);

	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Bullets", "lbullet","horizontal", 1, 60);

	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Bullets", "lbullet","vertical", 1, 60);

	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Bullets", "lbullet","-45oblique", 1, 60);

	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Bullets", "lbullet","45oblique", 1, 60);

	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Bullets", "fbullet","", 1, 4);

	delete temp;
	
}