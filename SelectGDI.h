#pragma once
#include "CustomDefine.h"

class SelectGDI
{
private:
	HDC m_hdc;
	HPEN m_hDefaultPen;
	HBRUSH m_hDefaultBrush;

public:
	SelectGDI(HDC _dc, PEN_TYPE _PenType);
	SelectGDI(HDC _dc, BRUSH_TYPE _BrushType);
	~SelectGDI();
};

