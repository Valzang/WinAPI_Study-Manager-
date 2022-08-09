#pragma once
#include "Object.h"
#include "Texture.h"
#include "ResourceManager.h"

class cPlayer :
    public cObject
{
private:
    cTexture* m_Tex;

public:
    cPlayer();
    virtual ~cPlayer();

    virtual void OnCollisionEnter(cCollider* _Other);
    virtual void OnCollision(cCollider* _Other);
    virtual void OnCollisionExit(cCollider* _Other);

    virtual void Update() override;
    virtual void Render(HDC _dc);
    void CreateBomb();
};

