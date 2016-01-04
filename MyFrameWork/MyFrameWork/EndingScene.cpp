#include "EndingScene.h"


EndingScene::EndingScene(void)
{
	BitMapFont* font = new BitMapFont("Resources\\Fonts\\font.png", 
									"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,\"\"|?!_-:;&(%'/ `abcdefghi",
									"fontByLinh",
									6,
									11,
									8,
									RectI(0, 0, 8, 8));

	Graphics::getInstance()->setFont(font);
    numOfLabel = 11;
    label = new Label[numOfLabel];

    for (int i = 0; i < numOfLabel; i++)
	{
        label[i] = Label();
		label[i].color = D3DCOLOR_ARGB(255, 255, 0, 0);
		label[i].size = 8;
		label[i].space = false;
		label[i].xPos = 10;

	}
	//label[4].yPos = 600;
	//label[5].yPos = 630;
	label[0].text = "CONGRATULATIONS!";
	label[1].text = "YOU HAVE DESTROYED THE VILE";
	label[2].text = "FALCON AND SAVE THE UNIVERSE.";
	label[3].text = "CONSIDER YOURSELF A HERO!";
    label[4].text = "DEVELOPERS: ";
    label[5].text = "HOANG MANH THANG";
    label[6].text = "BUI DINH LOC THO";
    label[7].text = "NGUYEN VAN QUANG";
    label[8].text = "NGUYEN THI HANG";
    label[9].text = " ----------THE END ---------- ";
    label[10].text = "SPACE - MENU GAME, ESC - EXIT";

	Sound::getInstance()->loadSound("Resources\\Sounds\\endingscene.wav", "endingscene");
	Sound::getInstance()->play("endingscene", false, 1);
}

void EndingScene::resetPos()
{
    for (int i = 0; i < numOfLabel; i++)
    {
        label[i].yPos = 256 + i * 30;
    }
}

EndingScene::~EndingScene(void)
{

}

void EndingScene::onUpdate()
{
	handleInput();

    for (int i = 0; i < numOfLabel; i++)
    {
        label[i].yPos -= 1;
    }

    if (label[numOfLabel - 1].yPos <= 0)
    {
        resetPos();
    }
}

void EndingScene::handleInput()
{
	while (!KeyBoard::getInstace()->isEmpty())
	{
		KeyEvent e = KeyBoard::getInstace()->readKey();
		switch (e.getCode())
		{
		case VK_SPACE:
			if (e.isRelease())
			{
				Sound::getInstance()->stop();
				SceneManager::getInstance()->createSceneWithRandomTransition(new StartingScene());
			}
			break;
		case VK_ESCAPE:
			if (e.isRelease())
			{
				PostQuitMessage(0);
			}
			break;
		}
	}
}
void EndingScene::render()
{
	Graphics::getInstance()->beginRender();
	Graphics::getInstance()->getSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND);

	for (int i = 0; i < numOfLabel; i++)
	{
		Graphics::getInstance()->drawText(label[i]);
	}

	Graphics::getInstance()->getSpriteHandler()->End();
	Graphics::getInstance()->endRender();
}