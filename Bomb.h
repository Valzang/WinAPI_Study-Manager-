#pragma once
#include "Object.h"
class cBomb :
    public cObject
{
private:
    float m_Theta; // ������ ������ ����.

public:
    cBomb();
    virtual ~cBomb();

    virtual void Update();
    virtual void Render(HDC _hdc);

    void SetDir(float _theta) { m_Theta = _theta; }
};

