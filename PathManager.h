#pragma once
#include "CustomDefine.h"
#include "Core.h"

class cPathManager
{
	SINGLETON2(cPathManager);

private:
	wchar_t m_sizeContentsPath[255];

public:
	void Init();
};

