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

	UINT		m_ID;		// 충돌체 고유한 ID값
	INT			m_isCollided;		// 충돌체 고유한 ID값


	
public:
	friend class cObject;

	cCollider();
	cCollider(const cCollider& _origin);
	~cCollider();

	// = 연산자 오버로딩 자체를 막음
	cCollider& operator=(cCollider & _origin) = delete;

	UINT GetID() { return m_ID; }

	void SetOffsetPos(Vec2 _Pos) { m_OffsetPos = _Pos; }
	void SetScale(Vec2 _Scale) { m_Scale = _Scale; }

	Vec2 GetOffsetPos() { return m_OffsetPos; }
	Vec2 GetScale() { return m_Scale; }

	Vec2 GetFinalPos() { return m_FinalPos; }

	void OnCollisionEnter(cCollider* _Other); // 첫 충돌 시 호출되는 함수
	void OnCollision(cCollider* _Other); // 충돌 중인 경우 호출되는 함수
	void OnCollisionExit(cCollider* _Other); // 충돌 탈출 시 호출되는 함수

	void LateUpdate();
	void Render(HDC _hdc);
	

};

