#pragma once

class Scene
{
public:
	Scene() {}
	virtual ~Scene() {}
	virtual void render()  = 0;
	virtual void onUpdate()  = 0;
};

