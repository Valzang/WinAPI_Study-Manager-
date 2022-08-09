#include "Core.h"

cCore::cCore() : m_hBit(NULL), m_hDC(NULL)
, m_hWnd(NULL), m_memDC(NULL), m_ptResolution({ 0, 0 }), m_arrBrush {}, m_arrPen {}
{

}

cCore::~cCore()
{
	// GetDC로 만든건 ReleaseDC로 지워야함.
	ReleaseDC(m_hWnd, m_hDC);

	// CreateCompatibleDC로 만든건 DeleteDC로 지워야함.
	DeleteDC(m_memDC);
	DeleteObject(m_hBit);

	for (int i = 0; i < (UINT)PEN_TYPE::END; ++i)
	{
		DeleteObject(m_arrPen[i]);
	}
}




void cCore::CreateBrushPen()
{
	m_arrBrush[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);

	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
}

int cCore::Init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	RECT rt = { 0, 0, m_ptResolution.x, m_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd);

	// 이중 버퍼링 용도의 비트맵과 DC 제작
	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBitmap);

	// 자주 사용할 펜 및 브러쉬 설정
	CreateBrushPen();

	// Manager 초기화
	cPathManager::GetInstance()->Init();
	cTimeManager::GetInstance()->Init();
	cKeyManager::GetInstance()->Init();
	cSceneManager::GetInstance()->Init();

	return S_OK;
}


void cCore::Progress()
{
	
	// Scene 업데이트 ==================================================
	cTimeManager::GetInstance()->Update();
	cKeyManager::GetInstance()->Update();
	cSceneManager::GetInstance()->Update();
	cCollisionManager::GetInstance()->Update();


	// Rendering ======================================================

	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);

	cSceneManager::GetInstance()->Render(m_memDC);

	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y
		   , m_memDC, 0, 0, SRCCOPY);

	cTimeManager::GetInstance()->Render(); // 프레임 표시


	// 이벤트 지연처리 (마무리 작업) ====================================
	cEventManager::GetInstance()->Update();

}
