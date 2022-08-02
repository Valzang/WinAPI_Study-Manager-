#pragma once
#include "CustomDefine.h"
#include "Object.h"
#include "Texture.h"
#include "Sound.h"

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

protected:

	cTexture* m_Tex;

public:

	cScene() : m_Tex(nullptr) {}
	virtual ~cScene();

	void SetName(const wstring& _strName) { m_sceneName = _strName; }
	const wstring& GetName() { return m_sceneName; }

	virtual void Enter() = 0; // �ش� ������ ���� �� ȣ��
	virtual void Exit() = 0;  // �ش� ������ Ż�� �� ȣ��

	// �Լ� ���Ǹ� ������Ͽ� �� �ÿ� inline ó�� �Ǽ� �Լ� ȣ�� ����� ��
	void AddObject(cObject* _Obj, GROUP_TYPE _Type) { m_arr_obj[(UINT)_Type].push_back(_Obj); }

	const vector<cObject*>& GetGroupObject(GROUP_TYPE _Type) { return m_arr_obj[(UINT)_Type]; }


	void Update();
	void LateUpdate();
	void Render(HDC _hdc);


};

