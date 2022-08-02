#include "Collider.h"
#include "Object.h"
#include "Core.h"
#include "SelectGDI.h"

cCollider::cCollider() : m_Owner(nullptr), m_OffsetPos()
{

}

cCollider::~cCollider()
{
}

void cCollider::FinalUpdate()
{
	// Object의 위치를 따라간다.
	//Vec2 ObjectPos = m_Owner->GetPos();
	//m_FinalPos = ObjectPos + m_OffsetPos;
	m_FinalPos = m_Owner->GetPos();
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
