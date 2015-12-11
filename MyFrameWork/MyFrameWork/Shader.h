#pragma once
#include <D3DX9Effect.h>
#include "Graphics.h"
class Shader
{
public:
	Shader(std::string sourceFile);
	~Shader(void);
	ID3DXEffect* getEffect()
	{
		return pShader;
	}
private:
	ID3DXEffect* pShader;
};

