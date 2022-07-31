#pragma once
#include "Object.h"
class cBomb :
    public cObject
{
private:
    float m_Theta; // ������ ������ ����.
    Vec2 m_Dir;     // ���ͷ� ������ ����.

public:
    cBomb();
    virtual ~cBomb();

    virtual void Update();
    virtual void Render(HDC _hdc);

    void SetDir(float _theta) { m_Theta = _theta; }
    void SetDir(Vec2 _Dir) { m_Dir = _Dir; m_Dir.Normalize(); }
};

