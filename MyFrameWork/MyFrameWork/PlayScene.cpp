#include "PlayScene.h"


PlayScene ::PlayScene(int mapID)
{

    pPlayer = new PlayerSprite();
    staticWeapon = new ObjectStaticWeapon(30, 60);
    //bridge->destroy();

    //std:: string mapName = "stage" + std::to_string(mapID);;
    std::string mapName = "map" + std::to_string(1);;
    pMap = new Map(mapName);
    int viewPortSize = pMap->getMapRect().width < pMap->getMapRect().height ? pMap->getMapRect().width : pMap->getMapRect().height;
    viewPort = new ViewPort(RectI(SCWIDTH / 2 - viewPortSize / 2, SCHEIGHT / 2 - viewPortSize / 2, viewPortSize, viewPortSize));
    cam = new Camera(viewPort, pMap->getMapRect());

}

void PlayScene::onCollision()
{
    pMap->onCollision(pPlayer, cam);
    pPlayer->setCameraTo(cam);
    pPlayer->updateThroughRect();
    pPlayer->setCameraRect(cam->getRect());
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
    pMap->onUpdate(pPlayer, cam);
    pMap->onSupportSprite(pPlayer);
    pPlayer->update();
    staticWeapon->update();
}
void PlayScene::render()
{
    Graphics::getInstance()->beginRender();
    
    pMap->draw(cam);
    pPlayer->draw(cam);
    staticWeapon->draw(cam);
    //Graphics::getInstance() ->drawText("TEST", RectI(200,220,50,50));



    Graphics::getInstance()->endRender();
}