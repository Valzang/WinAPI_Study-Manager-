#pragma once
#include "CustomDefine.h"
//#include "Object.h"

class cObject;

class cCollider
{
private:
	static UINT	g_NextID;

	cObject*	m_Owner;	// Collider를 소유하고 있는 오브젝트

	Vec2		m_OffsetPos; // 오브젝트로부터 상대적 기준이 되는 위치
	Vec2		m_FinalPos;  // LateUpdate를 통해 매 프레임마다 계산되어 확정되는 위치
	Vec2		m_Scale;		// 충돌체 크기

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

