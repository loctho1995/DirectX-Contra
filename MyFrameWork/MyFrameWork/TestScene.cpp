#include "TestScene.h"


TestScene::TestScene(void)
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


TestScene::~TestScene(void)
{
}
void TestScene:: render()
{
		Graphics::getInstance()->beginRender();

		Graphics::getInstance() ->drawText("IM SEXY", 5 , 0 , 100);

		Graphics::getInstance() ->drawText("AND I KNOW IT", 8 , 10 , 160, D3DCOLOR_ARGB(255, 255, 0, 0));

		Graphics::getInstance()->endRender();
}