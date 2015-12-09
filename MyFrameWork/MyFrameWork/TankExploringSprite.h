#include"BulletSprite.h"

class TankExploringSprite : public BulletSprite
{
public:
	TankExploringSprite(int x, int y);
	~TankExploringSprite();
	virtual void draw(Camera *cam);
	virtual void update();
	virtual void die();
};