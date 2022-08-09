#pragma once

#include "CustomDefine.h"
#include "KeyManager.h"
#include "TimeManager.h"
#include "Collider.h"

enum { PLAYER, PLATFORM, PLATFORM_ROTATE, MONSTER };


class cObject
{
private:
	Vec2 m_Pos;
	Vec2 m_Scale;	
	cCollider* m_Collider;

	int m_curClassType;

	bool m_Alive;

	void SetDead() { m_Alive = false; }

public:
	cObject() : m_Pos(), m_Scale(), m_Collider(nullptr), m_curClassType(), m_Alive(true) {};
	virtual ~cObject();

	void SetPos(Vec2 _Pos) { m_Pos = _Pos; }
	void SetScale(Vec2 _Scale) { m_Scale = _Scale; }

	void CreateCollider();
	cCollider* GetCollider() { return m_Collider; }
	void Component_Render(HDC _hdc);

	int GetCurClassType() { return m_curClassType; }

	bool IsDead() { return !m_Alive; }

	Vec2 GetPos() { return m_Pos; }
	Vec2 GetScale() { return m_Scale; }

	friend class cEventManager;

	virtual void Update() = 0;

	virtual	void OnCollisionEnter(cCollider* _Other) {} // ù �浹 �� ȣ��Ǵ� �Լ�
	virtual void OnCollision(cCollider* _Other) {} // �浹 ���� ��� ȣ��Ǵ� �Լ�
	virtual void OnCollisionExit(cCollider* _Other) {} // �浹 Ż�� �� ȣ��Ǵ� �Լ�

	// final Ű����� �ڽĿ��� �������̵� ���� ���ϰԲ�
	virtual void LateUpdate() final;
	virtual void Render(HDC _hdc);
};

