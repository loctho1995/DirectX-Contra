#include "HelpScene.h"


HelpScene::HelpScene()
{
    std::string mapName = "help";
    pMap = new Map(mapName);
    lifeTexture = new Texture("Resources\\Sprites\\player\\life00.png", "life00.png");
    int viewPortSize = pMap->getMapRect().width < pMap->getMapRect().height ? pMap->getMapRect().width : pMap->getMapRect().height;
    viewPort = new ViewPort(RectI(SCWIDTH / 2 - viewPortSize / 2, SCHEIGHT / 2 - viewPortSize / 2, viewPortSize, viewPortSize));
    cam = new Camera(viewPort, pMap->getResX(), pMap->getResY(), pMap->getMapRect(), pMap->getCameraTranslatePoint());
    pPlayer = new PlayerSprite(pMap->getResX(), pMap->getResY(), cam->getMoveDir());
    //label("Press B to back", 15, SCWIDTH / 2, SCHEIGHT / 2, NULL, true);

    label.color = D3DCOLOR_ARGB(255, 255, 0, 0);
    label.text = "Press B to back";
    label.size = 12;
    label.space = false;
    label.xPos = 10;
    label.yPos = 160;

    isPause = false;
    isFinish = false;
    isGameOver = false;
}


HelpScene::~HelpScene()
{
}

void HelpScene::onUpdate()
{
    update();
    onCollision();
    isFinish = pMap->isFinish();
    handleInput();
}

void HelpScene::update()
{
    pMap->onUpdate(pPlayer, cam);
    pMap->onSupportSprite(pPlayer);
    pPlayer->update();
    cam->update(pPlayer->getX(), pPlayer->getY());
    pPlayer->setCameraRect(cam->getRect());
}

void HelpScene::onCollision()
{
    pMap->onCollision(pPlayer, cam);
}

void HelpScene::handleInput()
{
    while (!KeyBoard::getInstace()->isEmpty())
    {
        KeyEvent e = KeyBoard::getInstace()->readKey();
        if (e.getCode() == UIComponents::getInstance()->getKey(UIComponents::SELECT))
        {
            if (e.isRelease())
            {
                isPause = !isPause;
            }
            break;
        }
        else if (e.getCode() == 0x53)
        {
            if (e.isRelease())
            {
                Sound::getInstance()->stop();
            }
        }
        else if (e.getCode() == 0x50)
        {
            if (e.isRelease())
            {
                Sound::getInstance()->play("background2.wav", true, 1);
            }
        }
        else if (!isPause)
        {
            char keyCode = e.getCode();
            if (keyCode == UIComponents::getInstance()->getKey(UIComponents::RIGHT))
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
            else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::LEFT))
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
            else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::UP))
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
            else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::DOWN))
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
            else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::JUMP))
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
            else if (keyCode == UIComponents::getInstance()->getKey(UIComponents::FIRE))
            {
                if (e.isPress())
                {
                    pPlayer->getState()->onFirePressed();
                }
            }
        }
    }

    KeyBoard::getInstace()->flush();
}

void HelpScene::render()
{
    Graphics::getInstance()->beginRender();
    pMap->draw(cam);
    pPlayer->draw(cam);
    Graphics::getInstance()->drawText(label);
    //Graphics::getInstance()->drawText(label);
    Graphics::getInstance()->endRender();
}