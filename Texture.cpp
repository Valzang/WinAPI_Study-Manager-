#include "Texture.h"
#include "Core.h"

cTexture::cTexture() : m_hBit(0), m_dc(0), m_Info{}
{
}

cTexture::~cTexture()
{
	DeleteDC(m_dc);
	DeleteObject(m_hBit);
}

void cTexture::Load(const wstring& _strFilePath)
{
	// 파일로부터 로딩한 데이터를 비트맵으로 생성
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	assert(m_hBit);

	// 비트맵과 연결할 DC도 있어야함.	
	m_dc = CreateCompatibleDC(cCore::GetInstance()->GetMainDC());

	// 비트맵과 DC 연결
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hPrevBit);

	// 비트맵 정보 : 가로 세로 길이도 알아야함.
	GetObject(m_hBit, sizeof(BITMAP), &m_Info);

}
