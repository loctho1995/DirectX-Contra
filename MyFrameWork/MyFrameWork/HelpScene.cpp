#include "HelpScene.h"


HelpScene::HelpScene()
{
    BitMapFont* font = new BitMapFont("Resources\\Fonts\\fontByLinh.png",
                                        "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,\"\"|?!_-:;&(%'/ ",
                                        "fontByLinh",
                                        6,
                                        9,
                                        8,
                                        RectI(0, 0, 8, 8));

    Graphics::getInstance()->setFont(font);

    std::string mapName = "help";
    pMap = new Map(mapName);
    lifeTexture = new Texture("Resources\\Sprites\\player\\life00.png", "life00.png");
    int viewPortSize = pMap->getMapRect().width < pMap->getMapRect().height ? pMap->getMapRect().width : pMap->getMapRect().height;
    viewPort = new ViewPort(RectI(SCWIDTH / 2 - viewPortSize / 2, SCHEIGHT / 2 - viewPortSize / 2, viewPortSize, viewPortSize));
    cam = new Camera(viewPort, pMap->getResX(), pMap->getResY(), pMap->getMapRect(), pMap->getCameraTranslatePoint());
    pPlayer = new PlayerSprite(pMap->getResX(), pMap->getResY(), cam->getMoveDir());
    //label("Press B to back", 15, SCWIDTH / 2, SCHEIGHT / 2, NULL, true);

    labelConversation.color = D3DCOLOR_ARGB(255, 255, 255, 0);
    labelConversation.text = "PRESS " + getKeyName(UIComponents::getInstance()->getDefaultKey(UIComponents::RIGHT)) + " TO MOVE FORWARD";
    labelConversation.size = 5;
    labelConversation.space = false;
    labelConversation.xPos = 20;
    labelConversation.yPos = 32;

    label.color = D3DCOLOR_ARGB(255, 255, 0, 0);
    label.text = "PRESS KEY ESC TO BACK";
    label.size = 10;
    label.space = false;
    label.xPos = SCWIDTH / 2 - 21 * label.size / 2;
    label.yPos = SCHEIGHT - 20;

    isPause = false;
    isHelpDown = false;
    isHelpFire = false;
    isHelpLeft = false;
    isHelpRight = false;
    isHelpUp = false;
    isHelpJump = false;
    isMoreInfo = false;
    isBulletHelp = false;
    isPlayerRead = false;

    conversationFrame = 90;
    frameChangeConversation = conversationFrame;
    conversationNum = 0;
}

std::string HelpScene::getKeyName(int index)
{
    char val = index;
    std::string str(&val);
    str.erase(1, str.length() - 1);

    switch (index)
    {
        case VK_RIGHT:
            return "ARROW RIGHT";

        case VK_LEFT:
            return "ARROW LEFT";

        case VK_UP:
            return "ARROW UP";

        case VK_DOWN:
            return "ARROW DOWN";

        case VK_SHIFT:
            return "SHIFT";

        case VK_CONTROL:
            return "CONTROL";

        case VK_ESCAPE:
            return "ESC";

        case VK_TAB:
            return "TAB";

        case VK_RETURN:
            return "RETURN";

        case VK_SPACE:
            return "SPACE";

        default:
            return str;
    }

    return "NA";
}

HelpScene::~HelpScene()
{
}

void HelpScene::onUpdate()
{
    update();
    onCollision();
    handleInput();
}

void HelpScene::update()
{
    if (!isBulletHelp)
    {
        if (pPlayer->getBody().x >= 350)
        {
            isPause = true;
            isPlayerRead = true;
            labelConversation.text = "THIS IS YOUR BULLET, SHOT IT TO GET";

            if (frameChangeConversation >= 0)
            {
                frameChangeConversation--;
            }
            else
            {
                labelConversation.text = "PRESS ENTER TO CONTINUE";
            }
        }
    }

    if (isPause)
    {
        return;
    }

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
        char keyCode = e.getCode();       

        //chuyen scene
        if (keyCode == VK_ESCAPE)
        {
            SceneManager::getInstance()->createScene(new LoadingScene());
        }

        if (isPause)
        {
            if (keyCode == VK_RETURN)
            {
                if (!isBulletHelp)
                {
                    isBulletHelp = true;

                    labelConversation.text = "NOW LETS ROCK";
                }

                isPause = false;
            }

            return;
        }

        if (keyCode == UIComponents::getInstance()->getKey(UIComponents::RIGHT))
        {
            if (!isHelpLeft && !isPlayerRead)
            {
                isHelpLeft = true;
                labelConversation.text = "PRESS " + getKeyName(UIComponents::getInstance()->getDefaultKey(UIComponents::LEFT)) + " TO MOVE BACKWARD";
            }

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
            if (!isHelpDown && isHelpLeft && !isPlayerRead)
            {
                isHelpDown = true;
                labelConversation.text = "PRESS " + getKeyName(UIComponents::getInstance()->getDefaultKey(UIComponents::DOWN)) + " TO LIE DOWN";
            }

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
            if (!isHelpJump && isHelpUp && !isPlayerRead)
            {
                isHelpJump = true;
                labelConversation.text = "PRESS " + getKeyName(UIComponents::getInstance()->getDefaultKey(UIComponents::JUMP)) + " TO JUMP";
            }

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
            if (!isHelpUp && isHelpDown && !isPlayerRead)
            {
                isHelpUp = true;
                labelConversation.text = "PRESS " + getKeyName(UIComponents::getInstance()->getDefaultKey(UIComponents::UP)) + " TO LOOK ABOVE";
            }

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
            if (!isHelpFire && isHelpJump && !isPlayerRead)
            {
                isHelpFire = true;
                labelConversation.text = "PRESS " + getKeyName(UIComponents::getInstance()->getDefaultKey(UIComponents::FIRE)) + " TO FIRE";
            }

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
            if (!isMoreInfo && !isPlayerRead)
            {
                isMoreInfo = true;
                labelConversation.text = "TIP: PRESS [DOWN] AND [JUMP] TO JUMP DOWN";
            }

            if (e.isPress())
            {
                pPlayer->getState()->onFirePressed();
            }
        }
    }

    KeyBoard::getInstace()->flush();
}

void HelpScene::render()
{

    Graphics::getInstance()->beginRender();
	Graphics::getInstance() ->getSpriteHandler() -> Begin(D3DXSPRITE_ALPHABLEND	);
    pMap->draw(cam);
    pPlayer->draw(cam);
    Graphics::getInstance()->drawText(label);
    Graphics::getInstance()->drawText(labelConversation);
	Graphics::getInstance() ->getSpriteHandler() -> End();
    Graphics::getInstance()->endRender();
}