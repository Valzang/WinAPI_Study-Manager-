#include "Monster.h"
#include "TimeManager.h"
#include "Collider.h"

cMonster::cMonster() : 	
	m_CenterPos(Vec2 { 0.f, 0.f })
	, m_Speed(100.f)
	, m_MaxDistance(50.f)
	, m_Direction(1)
{
	CreateCollider();
	GetCollider()->SetScale(Vec2(40.f, 40.f));
}

cMonster::~cMonster()
{
}

void cMonster::OnCollisionEnter(cCollider* _Other)
{
	cObject* OtherObj = _Other->GetObject();

	// enum을 오브젝트에 써서 받아온 오브젝트의 클래스 정보를 비교해서 사용가능
}

void cMonster::OnCollision(cCollider* _Other)
{
}

void cMonster::OnCollisionExit(cCollider* _Other)
{
}

void cMonster::Update()
{
	Vec2 CurPos = GetPos();

	// 진행 방향으로 시간당 m_Speed 만큼 이동
	CurPos.x += DELTA_TIME * m_Speed * m_Direction;

	float Dist = abs(m_CenterPos.x - CurPos.x) - m_MaxDistance;

	if (Dist > 0.f)
	{
		m_Direction *= -1;
		CurPos.x += Dist * m_Direction;
	}

	SetPos(CurPos);

	
}
