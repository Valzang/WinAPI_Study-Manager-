#include "SelectGDI.h"

#include "Core.h"

SelectGDI::SelectGDI(HDC _dc, PEN_TYPE _PenType)
	:m_hdc(_dc), m_hDefaultBrush(nullptr), m_hDefaultPen(nullptr)
{
	HPEN hPen = cCore::GetInstance()->GetPen(_PenType);
	m_hDefaultPen = (HPEN)SelectObject(_dc, hPen);
}

SelectGDI::SelectGDI(HDC _dc, BRUSH_TYPE _BrushType)
	: m_hdc(_dc), m_hDefaultBrush(nullptr), m_hDefaultPen(nullptr)
{
	HBRUSH hHollowBrush = cCore::GetInstance()->GetBrush(_BrushType);
	m_hDefaultBrush = (HBRUSH)SelectObject(_dc, hHollowBrush);
}

SelectGDI::~SelectGDI()
{
	SelectObject(m_hdc, m_hDefaultPen);
	SelectObject(m_hdc, m_hDefaultBrush);
}
