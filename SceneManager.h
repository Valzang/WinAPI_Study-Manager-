#pragma once
#include "CustomDefine.h"

class cScene;

class cSceneManager
{
	SINGLETON2(cSceneManager);

private:
	cScene* m_arrScene[(UINT)SCENE_TYPE::END]; // ������ �ִ� �� ���
	cScene* m_curScene; // ���� ��
	
public:
	void Init();
	void Update();
	void Render(HDC _hdc);

	cScene* GetCurScene() { return m_curScene; }
};
