#include "PlayScene.h"


PlayScene ::PlayScene(int mapID)
{
    std:: string mapName = "stage" + std::to_string(mapID);;
    pMap = new Map(mapName);
	pPlayer = new PlayerSprite(pMap ->getResX(), pMap ->getResY());
    int viewPortSize = pMap->getMapRect().width < pMap->getMapRect().height ? pMap->getMapRect().width : pMap->getMapRect().height;
    viewPort = new ViewPort(RectI(SCWIDTH / 2 - viewPortSize / 2, SCHEIGHT / 2 - viewPortSize / 2, viewPortSize, viewPortSize));
	cam = new Camera(viewPort,pMap ->getResX(), pMap ->getResY(), pMap->getMapRect(), pMap ->getCameraTranslatePoint());

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
        case 0x46:
            if (e.isPress())
            {
                pPlayer->getState()->onFirePressed();
            }
            break;

            //break;
        }
    }
}
void PlayScene::onUpdate()
{
    handleInput();
	update();
	onCollision();
}
void PlayScene::render()
{
    Graphics::getInstance()->beginRender();
    
    pMap->draw(cam);
    pPlayer->draw(cam);
    //Graphics::getInstance() ->drawText("TEST", RectI(200,220,50,50));



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