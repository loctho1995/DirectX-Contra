#include "PlayScene.h"


PlayScene ::PlayScene(int mapID)
{
    std:: string mapName = "stage" + std::to_string(mapID);;
    pMap = new Map(mapName);
	pPlayer = new PlayerSprite(pMap ->getResX(), pMap ->getResY());
    int viewPortSize = pMap->getMapRect().width < pMap->getMapRect().height ? pMap->getMapRect().width : pMap->getMapRect().height;
    viewPort = new ViewPort(RectI(SCWIDTH / 2 - viewPortSize / 2, SCHEIGHT / 2 - viewPortSize / 2, viewPortSize, viewPortSize));
	cam = new Camera(viewPort,pMap ->getResX(), pMap ->getResY(), pMap->getMapRect(), pMap ->getCameraTranslatePoint());
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
		if( e.getCode() == VK_RETURN)
		{
			if (e.isRelease())
			{
				isPause = !isPause;
			}
			break;
		}
		else if( !isPause)
		{
			switch (e.getCode())
			{


			case VK_RIGHT:
				if (e.isPress())
				{
					pPlayer->getState()->onMovePressed(Direction::createRight());
				}
				else
				{
					pPlayer->getState()->onMoveReleased(Direction::createRight());
				}
				break;
			case VK_LEFT:
				if (e.isPress())
				{
					pPlayer->getState()->onMovePressed(Direction::createLeft());
				}
				else
				{
					pPlayer->getState()->onMoveReleased(Direction::createLeft());
				}
				break;
			case VK_UP:
				if (e.isPress())
				{
					pPlayer->getState()->onVeticalDirectionPressed(Direction::createUp());
				}
				else
				{
					pPlayer->getState()->onVeticalDirectionReleased();
				}
				break;
			case VK_DOWN:
				if (e.isPress())
				{
					pPlayer->getState()->onVeticalDirectionPressed(Direction::createDown());
				}
				else
				{
					pPlayer->getState()->onVeticalDirectionReleased();
				}
				break;
			case VK_SPACE:
				if (e.isPress())
				{
					pPlayer->getState()->onJumpPressed();
				}
				else
				{
					pPlayer->getState()->onJumpRelease();
				}
				break;
			case 0x46: // F key
				if (e.isPress())
				{
					pPlayer->getState()->onFirePressed();
				}
				break;
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
			SceneManager::getInstance()->createScene(new GameOverScene(stageIndex));
		}
	}
	else if( isFinish )
	{
		count++;
		if( count == nTransitionFrames)
		{
			// changeScene to LoadingScene
		}
	}

	handleInput();

	if( !isPause )
	{
		update();
		onCollision();
		isFinish = pMap -> isFinish();
		isGameOver = pMap -> isGameOver();
	}	
}
void PlayScene::render()
{
    Graphics::getInstance()->beginRender();
    
    pMap->draw(cam);
    pPlayer->draw(cam);

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