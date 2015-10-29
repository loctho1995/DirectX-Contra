#include "PlayerSprite.h"
#include "PlayerJumpingState.h"

PlayerSprite::PlayerSprite()
{

	// Set up PlayerData
	pData = new PlayerData();

	pData->x  = 50;

	pData->y  = 50;

	pData -> ppTextureArrays = new TextureArray* [PlayerData::COUNT];

	pData->ppTextureArrays[PlayerData:: STAND ] = new TextureArray("Resources\\Sprites", "player", "stand", 1, 60  ); 

	pData->ppTextureArrays[PlayerData:: STAND ] -> setAnchorPoint(0.5f, 1.0f );

	pData->ppTextureArrays[PlayerData:: STANDUP ] = new TextureArray("Resources\\Sprites", "player", "standup", 1, 60  ); 

	pData->ppTextureArrays[PlayerData:: STANDUP ] -> setAnchorPoint(0.5f, 1.0f );

	pData->ppTextureArrays[PlayerData:: STANDUPNFIRE ] = new TextureArray("Resources\\Sprites", "player", "standupnfire", 1, 60  ); 

	pData->ppTextureArrays[PlayerData:: STANDUPNFIRE ] -> setAnchorPoint(0.5f, 1.0f );

	pData->ppTextureArrays[PlayerData:: STANDDOWN ] = new TextureArray("Resources\\Sprites", "player", "standdown", 1, 60  ); 

	pData->ppTextureArrays[PlayerData:: STANDDOWN ] -> setAnchorPoint(0.5f, 1.0f );

	pData->ppTextureArrays[PlayerData:: STANDNFIRE ] = new TextureArray("Resources\\Sprites", "player", "standnfire", 1, 60  ); 

	pData->ppTextureArrays[PlayerData:: STANDNFIRE ] -> setAnchorPoint(0.5f, 1.0f );

	pData->ppTextureArrays[PlayerData:: RUN ] = new TextureArray("Resources\\Sprites", "player", "run", 6, 8  ); 

	pData->ppTextureArrays[PlayerData:: RUN ] -> setAnchorPoint(0.5f, 1.0f );

	pData->ppTextureArrays[PlayerData::RUNNFIRE] = new TextureArray("Resources\\Sprites", "player", "runnfire", 6, 8, D3DCOLOR_XRGB(255, 255, 255));

	pData->ppTextureArrays[PlayerData:: RUNNFIRE ] -> setAnchorPoint(0.5f, 1.0f );


	pData->ppTextureArrays[PlayerData:: RUNDOWN ] = new TextureArray("Resources\\Sprites", "player", "rundown", 3, 8);

	pData->ppTextureArrays[PlayerData:: RUNDOWN ] -> setAnchorPoint(0.5f, 1.0f );


	pData->ppTextureArrays[PlayerData:: RUNUP ] = new TextureArray("Resources\\Sprites", "player", "runup", 3, 8);

	pData->ppTextureArrays[PlayerData:: RUNUP ] -> setAnchorPoint(0.5f, 1.0f );


	pData->ppTextureArrays[PlayerData:: JUMP ] = new TextureArray("Resources\\Sprites", "player", "jump", 4, 4); 

	pData->ppTextureArrays[PlayerData:: JUMP ] -> setAnchorPoint(0.5f, 1.0f );


	pData->ppTextureArrays[PlayerData:: FALL ] = new TextureArray("Resources\\Sprites", "player", "fall", 1, 60); 

	pData->ppTextureArrays[PlayerData:: FALL ] -> setAnchorPoint(0.5f, 1.0f );


	pData->ppTextureArrays[PlayerData:: DIVE ] = new TextureArray("Resources\\Sprites", "player", "dive", 1, 60  ); 

	pData->ppTextureArrays[PlayerData:: DIVE ] -> setAnchorPoint(0.5f, 1.0f );


	pData->ppTextureArrays[PlayerData:: DIVEUP ] = new TextureArray("Resources\\Sprites", "player", "diveup", 1, 60  ); 

	pData->ppTextureArrays[PlayerData:: DIVEUP ] -> setAnchorPoint(0.5f, 1.0f );


	pData->ppTextureArrays[PlayerData:: DIVEDOWN ] = new TextureArray("Resources\\Sprites", "player", "divedown", 1, 60  ); 

	pData->ppTextureArrays[PlayerData:: DIVEDOWN ] -> setAnchorPoint(0.5f, 1.0f );

	pData->ppTextureArrays[PlayerData:: DIVENFIRE ] = new TextureArray("Resources\\Sprites", "player", "divenfire", 1, 60  ); 

	pData->ppTextureArrays[PlayerData:: DIVENFIRE ] -> setAnchorPoint(0.5f, 1.0f );

	pData->ppTextureArrays[PlayerData:: CLIMP ] = new TextureArray("Resources\\Sprites", "player", "climb", 1, 60  ); 

	pData->ppTextureArrays[PlayerData:: CLIMP ] -> setAnchorPoint(0.5f, 1.0f );

	pData->ppTextureArrays[PlayerData:: DEAD ] = new TextureArray("Resources\\Sprites", "player", "dead", 4, 10 ); 

	pData->ppTextureArrays[PlayerData:: DEAD ] -> setAnchorPoint(0.5f, 1.0f );

	pData->ppTextureArrays[PlayerData:: LIE ] = new TextureArray("Resources\\Sprites", "player", "lie", 1, 60 );

	pData->ppTextureArrays[PlayerData:: LIE ] -> setAnchorPoint(0.5f, 1.0f );

	pData ->dir = Direction::createRight();

	pData ->verticalDir = Direction ::createNone();

	pData ->body = RectF( -8.0f, -27.0f, 16.0f, 27.0f);

	pData ->bulletType = PlayerData::BulletType::F;

	pData ->pState = new PlayerJumpingState(pData, false, 0.0f);

	
	

}

PlayerSprite:: ~PlayerSprite()
{
	for (int i = 0; i < PlayerData::COUNT; i++)
	{
		if(pData -> ppTextureArrays[i] != NULL )
			delete pData -> ppTextureArrays[i];
	}
	delete[] pData->ppTextureArrays;
}

void PlayerSprite::draw(Camera* cam)
{
	int isDraw  = 0;
	if( !pData ->isHittable)
	{
		isDraw = rand()% 2;
	}
	if (isDraw == 0)
	{
		if( pData -> dir.isRight())
		pData->ppTextureArrays[ pData->iCurrentArr ] -> draw(pData -> x, pData -> y , cam);
		else if( pData -> dir.isLeft())
			pData->ppTextureArrays[ pData->iCurrentArr ] -> drawFlipX(pData -> x, pData -> y , cam);

		for (int i = 0; i < pData ->Bullets.size(); i++)
		{
			pData ->Bullets[i] ->draw(cam);
		}
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
void PlayerSprite :: updateThroughRect()
{
	for (int i = 0; i < pData->cThroughRect.size(); i++)
	{
		if(!pData ->getBody().checkCollision( pData ->cThroughRect[i].rect))
		{
			pData->cThroughRect.erase( pData->cThroughRect.begin() + i );
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
	case PlayerData::F:
		return 1;
		break;
	case PlayerData::L:
		return 1;
		break;
	case PlayerData::M:
		return 1;
		break;
	case PlayerData::S:
		return 1;
		break;
	default:
		break;
	}
}