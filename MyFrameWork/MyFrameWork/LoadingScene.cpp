#include "LoadingScene.h"


LoadingScene::LoadingScene(void)
{
	BitMapFont* font = new BitMapFont("Resources\\Fonts\\fontAA.png", 
									"ABCDEFGHIKLMNOPQRSTUVXWZY",
									"fontAA",
									10,
									3,
									13,
									RectI(0, 0, 28, 30));
	Graphics::getInstance() ->setFont(font);

	nTransitionTime = 5 * 60;
	count = 0;
}


LoadingScene::~LoadingScene(void)
{
}

void LoadingScene::onUpdate()
{
	count++;
	if( count >= nTransitionTime)
	{
		SceneManager::getInstance() -> createScene( new PlayScene(1));
	}
}
void LoadingScene:: render()
{
		Graphics::getInstance()->beginRender();

		Graphics::getInstance() ->drawText("STAGE ONE", 8 , 10 , 160, D3DCOLOR_ARGB(255, 255, 0, 0));

		Graphics::getInstance() ->drawText("READY TO GO ", 8 , 10 , 240, D3DCOLOR_ARGB(255, 255, 0, 0));

		Graphics::getInstance()->endRender();
}