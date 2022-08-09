#pragma once
#include "Object.h"

class cMonster :
    public cObject
{
private:
    Vec2 m_CenterPos;
    float m_Speed;
    float m_MaxDistance;
    int m_Direction;

public:
    virtual void Update() override;
    cMonster();
    ~cMonster();

    virtual void OnCollisionEnter(cCollider* _Other);
    virtual void OnCollision(cCollider* _Other);
    virtual void OnCollisionExit(cCollider* _Other);

    float GetSpeed() { return m_Speed; }
    void SetSpeed(float _speed) { m_Speed = _speed; }
    void SetMaxDist(float _dist) { m_MaxDistance = _dist; }

    void SetCenterPos(Vec2 _Pos) { m_CenterPos = _Pos; }
};

