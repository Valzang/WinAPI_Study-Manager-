#include "Collider.h"
#include "Object.h"
#include "Core.h"
#include "SelectGDI.h"

UINT cCollider::g_NextID = 0;

cCollider::cCollider() : 
	m_Owner(nullptr), m_OffsetPos(), m_ID(g_NextID++), m_isCollided(false)
{

}

cCollider::cCollider(const cCollider& _origin) :
	m_Owner(nullptr), m_OffsetPos(_origin.m_OffsetPos),m_Scale(_origin.m_Scale), m_ID(g_NextID++), m_isCollided(_origin.m_isCollided)
{
}

cCollider::~cCollider()
{
}

void cCollider::OnCollisionEnter(cCollider* _Other)
{
	++m_isCollided;
	m_Owner->OnCollisionEnter(_Other);
}

void cCollider::OnCollision(cCollider* _Other)
{
	m_Owner->OnCollision(_Other);
}

void cCollider::OnCollisionExit(cCollider* _Other)
{
	--m_isCollided;
	m_Owner->OnCollisionExit(_Other);
}

void cCollider::LateUpdate()
{
	// Object의 위치를 따라간다.
	Vec2 ObjectPos = m_Owner->GetPos();
	m_FinalPos = ObjectPos + m_OffsetPos;

	assert(m_isCollided >= 0);
}

void cCollider::Render(HDC _hdc)
{
	PEN_TYPE curPen = PEN_TYPE::GREEN;
	if(m_isCollided)
		curPen = PEN_TYPE::RED;

	SelectGDI Pen(_hdc, curPen);
	SelectGDI Brush(_hdc, BRUSH_TYPE::HOLLOW);
	
	Rectangle(_hdc, 
			  (int)(m_FinalPos.x - m_Scale.x / 2.f), 
			  (int)(m_FinalPos.y - m_Scale.y / 2.f),
			  (int)(m_FinalPos.x + m_Scale.x / 2.f),
			  (int)(m_FinalPos.y + m_Scale.y / 2.f));

}
