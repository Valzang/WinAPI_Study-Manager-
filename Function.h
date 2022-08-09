#pragma once
#include "EventManager.h"
class cObject;

void CreateObject(cObject* _Obj, GROUP_TYPE _Group)
{
	tEvent event = {};;
	event.Event = EVENT_TYPE::CREATE_OBJECT;

	// ������Ʈ�� �ּ�
	event.lParam = (DWORD_PTR)_Obj;
	// ������Ʈ�� �׷�Ÿ��
	event.wParam = (DWORD_PTR)_Group;

	cEventManager::GetInstance()->AddEvent(event);
}