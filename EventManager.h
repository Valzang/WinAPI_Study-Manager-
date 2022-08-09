#pragma once
#include "CustomDefine.h"

struct tEvent
{
	EVENT_TYPE	Event;
	DWORD_PTR	lParam;
	DWORD_PTR	wParam;
};


class cEventManager
{
	SINGLETON2(cEventManager)

private:
	vector<tEvent> m_vecEvent;
	vector<cObject*> m_vecDead;

	void Excute(const tEvent& _event);

public:
	void Update(); 
	void AddEvent(const tEvent& _event) { m_vecEvent.push_back(_event); }
};

