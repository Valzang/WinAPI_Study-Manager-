#pragma once
#include "CustomDefine.h"
//#include "Object.h"

class cObject;

class cCollider
{
private:
	static UINT	g_NextID;

	cObject*	m_Owner;	// Collider�� �����ϰ� �ִ� ������Ʈ

	Vec2		m_OffsetPos; // ������Ʈ�κ��� ����� ������ �Ǵ� ��ġ
	Vec2		m_FinalPos;  // LateUpdate�� ���� �� �����Ӹ��� ���Ǿ� Ȯ���Ǵ� ��ġ
	Vec2		m_Scale;		// �浹ü ũ��

	UINT		m_ID;		// �浹ü ������ ID��
	INT			m_isCollided;		// �浹ü ������ ID��


	
public:
	friend class cObject;

	cCollider();
	cCollider(const cCollider& _origin);
	~cCollider();

	// = ������ �����ε� ��ü�� ����
	cCollider& operator=(cCollider & _origin) = delete;

	UINT GetID() { return m_ID; }

	void SetOffsetPos(Vec2 _Pos) { m_OffsetPos = _Pos; }
	void SetScale(Vec2 _Scale) { m_Scale = _Scale; }

	Vec2 GetOffsetPos() { return m_OffsetPos; }
	Vec2 GetScale() { return m_Scale; }

	Vec2 GetFinalPos() { return m_FinalPos; }

	void OnCollisionEnter(cCollider* _Other); // ù �浹 �� ȣ��Ǵ� �Լ�
	void OnCollision(cCollider* _Other); // �浹 ���� ��� ȣ��Ǵ� �Լ�
	void OnCollisionExit(cCollider* _Other); // �浹 Ż�� �� ȣ��Ǵ� �Լ�

	void LateUpdate();
	void Render(HDC _hdc);
	

};

