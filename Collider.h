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

	UINT		m_ID;


	
public:
	friend class cObject;

	cCollider();
	~cCollider();

	void SetOffsetPos(Vec2 _Pos) { m_OffsetPos = _Pos; }
	void SetScale(Vec2 _Scale) { m_Scale = _Scale; }

	Vec2 GetOffsetPos(Vec2 _Pos) { return m_OffsetPos; }
	Vec2 GetScale(Vec2 _Scale) { return m_Scale; }

	void LateUpdate();
	void Render(HDC _hdc);
	

};

