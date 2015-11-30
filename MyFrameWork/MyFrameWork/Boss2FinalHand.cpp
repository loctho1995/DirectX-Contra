#include "Boss2FinalHand.h"


Boss2FinalHand::Boss2FinalHand(float x, float y)
{
    this->pData = new SpriteData();
    this->pData->ppTextureArrays = new TextureArray *[1];
    this->pData->iCurrentArr = 0;    
    this->pData->x = x;
    this->pData->y = y;
    this->pData->ppTextureArrays[pData->iCurrentArr] = new TextureArray("Resources\\Sprites", "boss2final", "hand", 1, 1);

    defaultSetting();

}

Boss2FinalHand::~Boss2FinalHand()
{
}
