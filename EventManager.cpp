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
	// 이전 프레임에서 등록해둔 Dead Object들을 삭제한다
	for (UINT i = 0; i < m_vecDead.size(); ++i)
	{
		delete m_vecDead[i];
	}
	m_vecDead.clear();
	


	// 이벤트 처리
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
			// 오브젝트를 Dead 상태로 변경하여 삭제예정 오브젝트로 만들어두어 모아둠.
			cObject* DeadObj = (cObject*)_event.lParam;
			DeadObj->SetDead();
			m_vecDead.push_back(DeadObj);
		}
			break;

		case EVENT_TYPE::SCENE_CHANGE:

			break;
	}
}
