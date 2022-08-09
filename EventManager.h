#pragma once
#include "CustomDefine.h"

struct tEvent
{
	EVENT_TYPE	Event;
	DWORD		lParam;
	DWORD		wParam;
};


class cEventManager
{
	SINGLETON2(cEventManager)

private:
	vector<tEvent> m_vecEvent;

public:
	void Update(); 
};

