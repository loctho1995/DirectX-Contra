
#include "StartingScene.h"
#include "Graphics.h"
#include "KeyBoard.h"
#include "SceneManager.h"
StartingScene::StartingScene(void)
{
	BitMapFont* font = new BitMapFont("Resources\\Fonts\\fontAA.png", 
									"ABCDEFGHIKLMNOPQRSTUVXWZY",
									"fontAA",
									10,
									3,
									13,
									RectI(0, 0, 28, 30));
	Graphics::getInstance() ->setFont(font);
}


StartingScene::~StartingScene(void)
{
}

void StartingScene:: onUpdate()
{
	handleInput();
}

void StartingScene:: render()
{
	Graphics::getInstance()->beginRender();

	Graphics::getInstance() ->drawText("STARTING SCENE", 5 , 0 , 100);

	Graphics::getInstance() ->drawText("PRESS ENTER GUYS", 6 , 10 , 160, D3DCOLOR_ARGB(255, 255, 0, 0));

	Graphics::getInstance()->endRender();
}

void StartingScene:: handleInput()
{
	while (!KeyBoard::getInstace()->isEmpty())
	{
		KeyEvent e = KeyBoard::getInstace()->readKey();
		switch (e.getCode())
		{
		case VK_RETURN:
			if (e.isRelease())
			{
				SceneManager::getInstance() ->createScene( new LoadingScene());
			}
			break;
		}
	}
}