#pragma once

#include "CustomDefine.h"
#include "Object.h"


#include "TimeManager.h"
#include "SceneManager.h"
#include "PathManager.h"

class cCore
{
	SINGLETON2(cCore)
private:
	HWND	m_hWnd;	// ���� ������ �ڵ�
	POINT	m_ptResolution; // ���� ������ �ػ�
	HDC		m_hDC;			// ���� ������ �ڵ�� ���� DC
	HDC		m_memDC;		// m_hDC�� �����ؼ�, �̸� �׷��� DC
	HBITMAP m_hBit;

public:
	int Init(HWND _hWnd, POINT _ptResolution);

	HDC GetMainDC() { return m_hDC; }
	HWND GetMainHwnd() { return m_hWnd; }
	POINT GetResolution() { return m_ptResolution; }
	void Progress();
};

