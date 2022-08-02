#pragma once

#include "CustomDefine.h"
#include "Object.h"


#include "TimeManager.h"
#include "SceneManager.h"
#include "PathManager.h"
#include "CollisionManager.h"

class cCore
{
	SINGLETON2(cCore)
private:
	HWND	m_hWnd;	// 메인 윈도우 핸들
	POINT	m_ptResolution; // 메인 윈도우 해상도
	HDC		m_hDC;			// 메인 윈도우 핸들로 만들어낸 DC
	HDC		m_memDC;		// m_hDC를 복사해서, 미리 그려줄 DC
	HBITMAP m_hBit;

	HBRUSH m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN m_arrPen[(UINT)PEN_TYPE::END];

	void CreateBrushPen();

public:
	int Init(HWND _hWnd, POINT _ptResolution);

	HDC GetMainDC() { return m_hDC; }
	HWND GetMainHwnd() { return m_hWnd; }
	POINT GetResolution() { return m_ptResolution; }
	void Progress();

	HBRUSH GetBrush(BRUSH_TYPE _Type) { return m_arrBrush[(UINT)_Type];	}
	HPEN GetPen(PEN_TYPE _Type) { return m_arrPen[(UINT)_Type]; }
};

