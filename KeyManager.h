#pragma once
#include "CustomDefine.h"

// 1. ������ ����ȭ
// Ű �Ŵ����� ���� : ���� ������ ������ ���� Ű�� ����, ������ �̺�Ʈ�� ��������.

// 2. Ű �Է� �̺�Ʈ ó��
// �ѹ� ���ȴ���, �� ���ȴ���, ���ȴٰ� ����������, �� ���ȴ���

// 3. ���� ������ â�� Ȱ��ȭ �Ǿ����� ������ Ű �Է� ó��



enum class KEY_STATE
{
	NONE, // ������ ���� ���� ( ������ �� ������ )
	DOWN, // ó�� ���� ����
	HOLD, // ������ �ִ� ����
	UP, // ������ ���� ���� ( ������ ������ )
};

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,

	// 1P ������
	A, S, I, J, K, L,


	// 2P ������	
	Delete, End, Num8, Num4, Num5, Num6,

	Player2_START, // 2P �ѱ�
	P, // Pause
	ESC, // Escape
	Enter, // Enter
	LAST // enum�� ��
};

static int arrVK[(int)KEY::LAST] =
{
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,

	// 1P ������
	'A', 'S', 'I', 'J', 'K', 'L',

	// 2P ������
	VK_DELETE, VK_END, VK_NUMPAD8, VK_NUMPAD4, VK_NUMPAD5, VK_NUMPAD6,

	'2', // 2P ����
	'P', // Pause
	VK_ESCAPE, // Escape
	VK_RETURN, // Enter
};

struct KeyInfo
{
	KEY_STATE mKeyState; // Ű�� ���°�
	bool wasPushed; // ���� �����ӿ� ���ȴ���
};


class cKeyManager
{
	SINGLETON2(cKeyManager)

private:
	vector<KeyInfo> m_vecKey;
	//HWND m_hWnd = NULL;

public:
	void Init();
	void Update();
	KEY_STATE GetKeyState(KEY _key);
};

