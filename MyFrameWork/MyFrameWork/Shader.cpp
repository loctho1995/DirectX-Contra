#include "Shader.h"
#include <iostream>

Shader::Shader(std::string sourceFile)
{
	HRESULT hr;
	ID3DXBuffer* error = NULL;
	hr = D3DXCreateEffectFromFileA(Graphics::getInstance()->getDevice(), sourceFile.c_str(), 0, 0, 0, 0, &pShader ,&error);
	if(FAILED(hr))
	{
		if(error)
		{
			std :: cout << (char*)error ->GetBufferPointer();
		}
		else
		{
			std::cout <<"cant find shader";
		}
	}
}


Shader::~Shader(void)
{
	if(pShader)
	{
		pShader ->Release();
		pShader = NULL;
	}
}
