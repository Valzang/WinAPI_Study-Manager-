#include "EventManager.h"
#include "Object.h"
#include "SceneManager.h"
#include "Scene.h"

cEventManager::cEventManager()
{

}

cEventManager::~cEventManager()
{

}




void cEventManager::Update()
{
	// ���� �����ӿ��� ����ص� Dead Object���� �����Ѵ�
	for (UINT i = 0; i < m_vecDead.size(); ++i)
	{
		delete m_vecDead[i];
	}
	m_vecDead.clear();
	


	// �̺�Ʈ ó��
	for (UINT i = 0; i < m_vecEvent.size(); ++i)
	{
		Excute(m_vecEvent[i]);
	}

	m_vecEvent.clear();
}

void cEventManager::Excute(const tEvent& _event)
{
	switch (_event.Event)
	{
		case EVENT_TYPE::CREATE_OBJECT:
		{
			cObject* NewObj = (cObject*)_event.lParam;
			GROUP_TYPE Type = (GROUP_TYPE)_event.wParam;

			cSceneManager::GetInstance()->GetCurScene()->AddObject(NewObj, Type);
		}
			break;

		case EVENT_TYPE::DELETE_OBJECT:
		{
			// ������Ʈ�� Dead ���·� �����Ͽ� �������� ������Ʈ�� �����ξ� ��Ƶ�.
			cObject* DeadObj = (cObject*)_event.lParam;
			DeadObj->SetDead();
			m_vecDead.push_back(DeadObj);
		}
			break;

		case EVENT_TYPE::SCENE_CHANGE:

			break;
	}
}
