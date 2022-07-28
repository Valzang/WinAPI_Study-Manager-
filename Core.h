#pragma once
#include "CustomDefine.h"
#include "TimeManager.h"
#include "SceneManager.h"

class CCore
{
	SINGLETON2(CCore)
private:
	HWND	m_hWnd;	// ���� ������ �ڵ�
	POINT	m_ptResolution; // ���� ������ �ػ�
	HDC		m_hDC;
	HDC		m_memDC;
	HBITMAP m_hBit;

public:
	int Init(HWND _hWnd, POINT _ptResolution);

	HWND GetMainHwnd() { return m_hWnd; }
	POINT GetResolution() { return m_ptResolution; }
	void Progress();
	void Update();
	void Render();
};

