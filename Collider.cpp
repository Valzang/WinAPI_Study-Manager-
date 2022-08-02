#include "Collider.h"
#include "Object.h"
#include "Core.h"
#include "SelectGDI.h"

UINT cCollider::g_NextID = 0;

cCollider::cCollider() : m_Owner(nullptr), m_OffsetPos(), m_ID(g_NextID++)
{

}

cCollider::~cCollider()
{
}

void cCollider::LateUpdate()
{
	// Object의 위치를 따라간다.
	Vec2 ObjectPos = m_Owner->GetPos();
	m_FinalPos = ObjectPos + m_OffsetPos;
}

void cCollider::Render(HDC _hdc)
{
	SelectGDI Pen(_hdc, PEN_TYPE::GREEN);
	SelectGDI Brush(_hdc, BRUSH_TYPE::HOLLOW);
	
	Rectangle(_hdc, 
			  (int)(m_FinalPos.x - m_Scale.x / 2.f), 
			  (int)(m_FinalPos.y - m_Scale.y / 2.f),
			  (int)(m_FinalPos.x + m_Scale.x / 2.f),
			  (int)(m_FinalPos.y + m_Scale.y / 2.f));

}
