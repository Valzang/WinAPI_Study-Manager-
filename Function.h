#pragma once
#include "EventManager.h"
class cObject;

void CreateObject(cObject* _Obj, GROUP_TYPE _Group)
{
	tEvent event = {};;
	event.Event = EVENT_TYPE::CREATE_OBJECT;

	// 오브젝트의 주소
	event.lParam = (DWORD_PTR)_Obj;
	// 오브젝트의 그룹타입
	event.wParam = (DWORD_PTR)_Group;

	cEventManager::GetInstance()->AddEvent(event);
}