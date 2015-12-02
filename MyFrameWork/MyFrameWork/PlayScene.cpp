#include "PlayScene.h"


PlayScene ::PlayScene()
{
    std:: string mapName = "stage" + std::to_string(UIComponents::getInstance() ->getCurrentStage());
    pMap = new Map(mapName);
	
	lifeTexture = new Texture("Resources\\Sprites\\player\\life00.png", "life00.png");
    int viewPortSize = pMap->getMapRect().width < pMap->getMapRect().height ? pMap->getMapRect().width : pMap->getMapRect().height;
    viewPort = new ViewPort(RectI(SCWIDTH / 2 - viewPortSize / 2, SCHEIGHT / 2 - viewPortSize / 2, viewPortSize, viewPortSize));
	cam = new Camera(viewPort,pMap ->getResX(), pMap ->getResY(), pMap->getMapRect(), pMap ->getCameraTranslatePoint());
	pPlayer = new PlayerSprite(pMap ->getResX(), pMap ->getResY(), cam ->getMoveDir());
	isPause = false;
	isFinish = false;
	isGameOver = false;
	nTransitionFrames = 5 * 60;
	count = 0;
}

void PlayScene::onCollision()
{
    pMap->onCollision(pPlayer, cam);
}

void PlayScene::handleInput()
{
    while (!KeyBoard::getInstace()->isEmpty())
    {
        KeyEvent e = KeyBoard::getInstace()->readKey();
		if( e.getCode() == UIComponents::getInstance() ->getKey(UIComponents::SELECT) )
		{
			if (e.isRelease())
			{
				isPause = !isPause;
			}
			break;
		}
		else if ( e.getCode() == 0x53 ) 
		{
			if (e.isRelease())
			{
				Sound::getInstance() ->stop();
			}
		}
		else if ( e.getCode() == 0x50)
		{
			if (e.isRelease())
			{
				Sound::getInstance() ->play("background2.wav", true, 1);
			}
		}
		else if( !isPause)
		{
			char keyCode = e.getCode();
			if( keyCode == UIComponents::getInstance() ->getKey(UIComponents::RIGHT) )
			{
				if (e.isPress())
				{
					pPlayer->getState()->onMovePressed(Direction::createRight());
				}
				else
				{
					pPlayer->getState()->onMoveReleased(Direction::createRight());
				}
			}
			else if ( keyCode == UIComponents::getInstance() -> getKey(UIComponents::LEFT))
			{
				if (e.isPress())
				{
					pPlayer->getState()->onMovePressed(Direction::createLeft());
				}
				else
				{
					pPlayer->getState()->onMoveReleased(Direction::createLeft());
				}
			}
			else if ( keyCode == UIComponents::getInstance() -> getKey(UIComponents::UP ))
			{
				if (e.isPress())
				{
					pPlayer->getState()->onVeticalDirectionPressed(Direction::createUp());
				}
				else
				{
					pPlayer->getState()->onVeticalDirectionReleased();
				}
			}
			else if( keyCode == UIComponents::getInstance() -> getKey(UIComponents::DOWN ))
			{
				if (e.isPress())
				{
					pPlayer->getState()->onVeticalDirectionPressed(Direction::createDown());
				}
				else
				{
					pPlayer->getState()->onVeticalDirectionReleased();
				}
			}
			else if( keyCode == UIComponents::getInstance() -> getKey(UIComponents::JUMP ))
			{
				if (e.isPress())
				{
					pPlayer->getState()->onJumpPressed();
				}
				else
				{
					pPlayer->getState()->onJumpRelease();
				}
			}
			else if( keyCode == UIComponents::getInstance() -> getKey(UIComponents::FIRE ))
			{
				if (e.isPress())
				{
					pPlayer->getState()->onFirePressed();
				}
			}		
        }
    }

	KeyBoard::getInstace() ->flush();

}
void PlayScene::onUpdate()
{
	if( isGameOver )
	{
		count++;
		if( count == nTransitionFrames)
		{
			SceneManager::getInstance()->createScene(new GameOverScene());
			return;
		}
	}
	else if( isFinish )
	{
		count++;
		if( count == nTransitionFrames)
		{
			if( UIComponents::getInstance() ->getCurrentStage() < 5 )
			{
				UIComponents::getInstance() ->setStage( UIComponents::getInstance() ->getCurrentStage() + 2 );
				SceneManager::getInstance()->createScene(new LoadingScene());
			}
			else
			{
				SceneManager::getInstance()->createScene(new EndingScene());
			}
			return;
		}
	}

	handleInput();

	if( !isPause )
	{
		update();
		onCollision();
		isFinish = pMap -> isFinish();
		if(UIComponents::getInstance() ->getLifes() <= 0)
		{
			isGameOver = true;
		}
	}	
}
void PlayScene::render()
{
    Graphics::getInstance()->beginRender();
    
    pMap->draw(cam);
    pPlayer->draw(cam);
	int lifes = min (UIComponents::getInstance() ->getLifes() , 5);
	int x = 0;
	int y = 0;
	int offset = 16;
	for (int i = 0; i < lifes - 1 ; i++)
	{
		lifeTexture ->draw(x, y);
		x += offset;
	}
    Graphics::getInstance()->endRender();
}

void PlayScene::  update()
{
	pMap->onUpdate(pPlayer, cam);
    pMap->onSupportSprite(pPlayer);
    pPlayer->update();
	cam ->update( pPlayer->getX(), pPlayer->getY() );
	pPlayer -> setCameraRect (cam ->getRect());
}