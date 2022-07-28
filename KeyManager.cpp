#include "KeyManager.h"

cKeyManager::cKeyManager()
{

}

cKeyManager::~cKeyManager()
{

}


void cKeyManager::Init()
{
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		m_vecKey.push_back(KeyInfo { KEY_STATE::NONE, false });
	}
}

void cKeyManager::Update()
{
	//��Ŀ�� �� �����찡 ��������
	HWND hWnd = GetFocus();

	// ��Ŀ�� �� �����찡 �ִٸ�
	if (hWnd != nullptr)
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			// Ű�� �����ִٸ�
			if (GetAsyncKeyState(arrVK[i]) & 0x8000)
			{
				if (m_vecKey[i].wasPushed)
					m_vecKey[i].mKeyState = KEY_STATE::HOLD;
				else
					m_vecKey[i].mKeyState = KEY_STATE::DOWN;
				m_vecKey[i].wasPushed = true;
			}
			else
			{
				// ������ �����־��ٸ�
				if (m_vecKey[i].wasPushed)
					m_vecKey[i].mKeyState = KEY_STATE::UP;
				else
					m_vecKey[i].mKeyState = KEY_STATE::NONE;
				m_vecKey[i].wasPushed = false;
			}
		}
	}

	// ��Ŀ�� �� �����찡 ���ٸ�
	else
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			m_vecKey[i].wasPushed = false;

			if (m_vecKey[i].mKeyState == KEY_STATE::DOWN
				|| m_vecKey[i].mKeyState == KEY_STATE::HOLD)
				m_vecKey[i].mKeyState = KEY_STATE::UP;
			else if (m_vecKey[i].mKeyState == KEY_STATE::UP)
				m_vecKey[i].mKeyState = KEY_STATE::NONE;
		}
	}
}

KEY_STATE cKeyManager::GetKeyState(KEY _key)
{
	return m_vecKey[(int)_key].mKeyState;
}
