#include "Object.h"

void cObject::Render(HDC _hdc)
{
	// Rectangle�� ������
	Rectangle(_hdc, (int)(m_Pos.x - m_Scale.x / 2.f), (int)(m_Pos.y - m_Scale.y / 2.f),
			  (int)(m_Pos.x + m_Scale.x / 2.f), (int)(m_Pos.y + m_Scale.y / 2.f));
}
