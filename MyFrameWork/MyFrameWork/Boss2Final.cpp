#include "Boss2Final.h"


Boss2Final::Boss2Final()
{
}


Boss2Final::~Boss2Final()
{
}

void Boss2Final::loadResources()
{
    TextureArray *temp = new TextureArray("Resources\\Sprites", "boss2final", "joint", 1, 1);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "boss2final", "hand", 1, 1);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "boss2final", "bodyshut", 3, 15);
    delete temp;

    temp = new TextureArray("Resources\\Sprites", "boss2final", "body", 5, 15);
    delete temp;
}