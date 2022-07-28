#pragma once
#include "CustomDefine.h"
#include "Object.h"

// ��� ������ �θ� ���ʹ� �ٸ���
// ���漱���� ����� �� �ش� class ������ �ٲ� �������� ����.
// ��, ������ �ð��� �̵�.
// ��� �����ͷ� �ۿ� �� ��
class cObject;

class cScene
{
private:
	// ������Ʈ���� ���� ���͸� �׷� ������ŭ ����
	vector<cObject*> m_arr_obj[(UINT)GROUP_TYPE::END];
	wstring m_sceneName;

public:
	// �Լ� ���Ǹ� ������Ͽ� �� �ÿ� inline ó�� �Ǽ� �Լ� ȣ�� ����� ��
	void AddObject(cObject* _Obj, GROUP_TYPE _Type)
	{
		m_arr_obj[(UINT)_Type].push_back(_Obj);
	}

	cScene() {}
	virtual ~cScene();

	void SetName(const wstring& _strName) { m_sceneName = _strName; }
	const wstring& GetName() { return m_sceneName; }

	virtual void Enter() = 0; // �ش� ������ ���� �� ȣ��
	virtual void Exit() = 0;  // �ش� ������ Ż�� �� ȣ��

	void Update();
	void Render(HDC _hdc);


};

