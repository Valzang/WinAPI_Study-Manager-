#pragma once

#include "CustomDefine.h"
#include "Core.h"

class cTimeManager
{
	SINGLETON2(cTimeManager);

private:
	LARGE_INTEGER m_curCount;
	LARGE_INTEGER m_prevCount;
	LARGE_INTEGER m_curFrequency;

	double m_deltaTime; // ������ ������ �ð� ��
	double m_accumlate; // 1�� üũ�� ���� ���� �ð� ��
	UINT m_callCount; // �Լ� ȣ�� Ƚ��
	UINT m_FPS; // FPS ( �ʴ� ������ �� )

public:
	void Init();
	void Update();
	void Render();

	float GetDT() { return (float)m_deltaTime; }

};