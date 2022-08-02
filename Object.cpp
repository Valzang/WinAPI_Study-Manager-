#include "Object.h"

cObject::~cObject()
{
	if (m_Collider != nullptr)
	{
		delete m_Collider;
		m_Collider = nullptr;
	}
}

void cObject::CreateCollider()
{
	m_Collider = new cCollider;
	m_Collider->m_Owner = this;
}

void cObject::Component_Render(HDC _hdc)
{
	if (m_Collider != nullptr)
	{
		m_Collider->Render(_hdc);
	}
}

void cObject::LateUpdate()
{
	if (m_Collider != nullptr)
		m_Collider->LateUpdate();
}

void cObject::Render(HDC _hdc)
{
	// Rectangle은 예시임
	Rectangle(_hdc, (int)(m_Pos.x - m_Scale.x / 2.f), (int)(m_Pos.y - m_Scale.y / 2.f),
			  (int)(m_Pos.x + m_Scale.x / 2.f), (int)(m_Pos.y + m_Scale.y / 2.f));

	Component_Render(_hdc);
	
}
