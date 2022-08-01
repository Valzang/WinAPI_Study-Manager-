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
	// ���Ϸκ��� �ε��� �����͸� ��Ʈ������ ����
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	assert(m_hBit);

	// ��Ʈ�ʰ� ������ DC�� �־����.	
	m_dc = CreateCompatibleDC(cCore::GetInstance()->GetMainDC());

	// ��Ʈ�ʰ� DC ����
	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hPrevBit);

	// ��Ʈ�� ���� : ���� ���� ���̵� �˾ƾ���.
	GetObject(m_hBit, sizeof(BITMAP), &m_Info);

}
