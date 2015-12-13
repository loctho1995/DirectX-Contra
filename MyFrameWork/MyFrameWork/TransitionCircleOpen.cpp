#include "TransitionCircleOpen.h"


TransitionCircleOpen::TransitionCircleOpen(float speed)
{
    this->speed = speed;
    this->radius = 0;

    shader = new Shader("Resources\\Shader\\transitioncircleopen.fx");
}


TransitionCircleOpen::~TransitionCircleOpen()
{
}

void TransitionCircleOpen::update()
{
    radius += speed;

    Graphics::getInstance()->beginRender();

    unsigned int Passes = 0;
    shader->getEffect()->Begin(&Passes, 0);

    D3DXMATRIX mtxViewProj;
    D3DXMatrixIdentity(&mtxViewProj);
    mtxViewProj._11 = 2.0;
    mtxViewProj._22 = -2.0; //toa do loz texel no nguoc voi toa do hlsl nen phai cover
    mtxViewProj._41 = 1.0;
    mtxViewProj._42 = 1.0;

    shader->getEffect()->SetMatrix("WorldViewProj", &(mtxViewProj));
    shader->getEffect()->SetTexture("texture0", texture0);
    shader->getEffect()->SetTexture("texture1", texture1);
    shader->getEffect()->SetFloat("radius", radius);

    for (int i = 0; i < Passes; ++i)
    {
        shader->getEffect()->BeginPass(i);

        Graphics::getInstance()->getDevice()->SetStreamSource(0, vertexBuffer, 0, sizeof(VertexData));
        Graphics::getInstance()->getDevice()->SetFVF(D3DFVF_CUSTOMVERTEX);
        Graphics::getInstance()->getDevice()->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

        shader->getEffect()->EndPass();
    }

    shader->getEffect()->End();
    Graphics::getInstance()->endRender();
}

bool TransitionCircleOpen::isFinish()
{
    return radius >= 0.8;
}

void TransitionCircleOpen::doAfterSetScene()
{
    D3DXCreateTexture(Graphics::getInstance()->getDevice(), SCWIDTH, SCHEIGHT, D3DX_DEFAULT,
        D3DUSAGE_RENDERTARGET, D3DFMT_A8B8G8R8, D3DPOOL_DEFAULT, &texture0);

    D3DXCreateTexture(Graphics::getInstance()->getDevice(), SCWIDTH, SCHEIGHT, D3DX_DEFAULT,
        D3DUSAGE_RENDERTARGET, D3DFMT_A8B8G8R8, D3DPOOL_DEFAULT, &texture1);
    Graphics::getInstance()->isAllowPresent = false;

    IDirect3DSurface9 *surface, *backsurface;
    this->sceneDest->render();
    texture1->GetSurfaceLevel(0, &surface);
    Graphics::getInstance()->getDevice()->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backsurface);

    D3DXLoadSurfaceFromSurface(surface, NULL, NULL, backsurface, NULL, NULL, D3DX_FILTER_NONE, 0);
    surface->Release();
    surface = nullptr;

    this->sceneSource->render();
    texture0->GetSurfaceLevel(0, &surface);
    D3DXLoadSurfaceFromSurface(surface, NULL, NULL, backsurface, NULL, NULL, D3DX_FILTER_NONE, 0);
    surface->Release();

    Graphics::getInstance()->isAllowPresent = true;
}