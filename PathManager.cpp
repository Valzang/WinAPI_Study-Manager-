#include "PathManager.h"

cPathManager::cPathManager() : m_sizeContentsPath{}
{
	
}
cPathManager::~cPathManager()
{

}

void cPathManager::Init()
{
	GetCurrentDirectory(255, m_sizeContentsPath);

	// ���� ������ �̵�
	int Len = (int)wcslen(m_sizeContentsPath);
	for (int i = Len - 1; i >= 0; --i)
	{
		if (m_sizeContentsPath[i] == '\\')
		{
			m_sizeContentsPath[i] = '\0';
			break;
		}
	}

	wcscat_s(m_sizeContentsPath, 255, L"\\bin\\resource\\");

	// . + bin \\ content \\

	//SetWindowText(CCore::GetInstance()->GetMainHwnd(), m_sizeContentsPath); //���� ��θ� ������ Ÿ��Ʋ�� ����ֱ�
}
