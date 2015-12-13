#pragma once
#include "Scene.h"
#include "Shader.h"

#define D3DFVF_CUSTOMVERTEX ( D3DFVF_XYZ | D3DFVF_TEX1 )

class TransitionEffect
{
public:

    struct VertexData
    {
        D3DXVECTOR3 Position;
        D3DCOLOR Color;
    };

    TransitionEffect()
    { 
        initvertexData(); 
    }

    virtual void update()
    {
    }

    virtual bool isFinish(){ return false; }

    virtual void setScenes(Scene *source, Scene *dest)
    {
        sceneSource = source;
        sceneDest = dest;

        doAfterSetScene();
        replaceNullScene();
    }

    virtual void doAfterSetScene()
    {
    }

    virtual void replaceNullScene()
    {
        //SceneManager::getInstance()->createScene(new NullScene());
    }

    virtual void initvertexData()
    {
        VertexData vertexData[] =
        {
            //  x     y     z       color
            { D3DXVECTOR3(-1.0f, 1.0f, 0.0f), D3DCOLOR_XRGB(255, 0, 0) },
            { D3DXVECTOR3(1.0f, 1.0f, 0.0f), D3DCOLOR_XRGB(0, 255, 0) },
            { D3DXVECTOR3(-1.0f, -1.0f, 0.0f), D3DCOLOR_XRGB(0, 0, 255) },
            { D3DXVECTOR3(1.0f, -1.0f, 0.0f), D3DCOLOR_XRGB(10, 150, 250) }
        };

        unsigned int vertexDataSize = 4 * sizeof(VertexData);

        //create vertex buffer
        Graphics::getInstance()->getDevice()->CreateVertexBuffer(vertexDataSize, D3DUSAGE_WRITEONLY, D3DFVF_CUSTOMVERTEX,
            D3DPOOL_DEFAULT, &vertexBuffer, 0);

        void *pVertices = NULL;
        vertexBuffer->Lock(0, vertexDataSize, (void**)&pVertices, 0);
        memcpy(pVertices, vertexData, vertexDataSize);
        vertexBuffer->Unlock();
    }

    Scene *sceneSource, *sceneDest;

protected:
    Shader *shader;
    LPDIRECT3DVERTEXBUFFER9 vertexBuffer;
};