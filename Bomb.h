#pragma once
#include "Object.h"
class cBomb :
    public cObject
{
private:
    float m_Theta; // 각도로 방향을 정함.
    Vec2 m_Dir;     // 벡터로 방향을 정함.

public:
    cBomb();
    virtual ~cBomb();

    virtual void Update();
    virtual void Render(HDC _hdc);

    virtual void OnCollisionEnter(cCollider* _Other);
    virtual void OnCollision(cCollider* _Other);
    virtual void OnCollisionExit(cCollider* _Other);

    void SetDir(float _theta) { m_Theta = _theta; }
    void SetDir(Vec2 _Dir) { m_Dir = _Dir; m_Dir.Normalize(); }
};

