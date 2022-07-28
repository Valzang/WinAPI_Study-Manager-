#pragma once
#include "Object.h"
class cBomb :
    public cObject
{
private:
    float m_Direction; // �� �Ʒ� ����

public:
    cBomb();
    virtual ~cBomb();

    virtual void Update();
    virtual void Render(HDC _hdc);
    void SetDirection(bool _Up)
    {
        if (_Up)
            m_Direction = -1.f;
        else
            m_Direction = 1.f;
    }
};

