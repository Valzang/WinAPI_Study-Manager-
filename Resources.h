#pragma once
#include "CustomDefine.h"

class cResource
{
private:
	wstring m_strKey;				// 리소스 키값
	wstring m_strRelativePath;		// 리소스 상대경로

public:
	void SetKey(const wstring& _strKey) { m_strKey = _strKey; }
	void SetRelativePath(const wstring& _strPath) { m_strRelativePath = _strPath; }

	const wstring& GetKey() { return m_strKey; }
	const wstring& GetRelativePath() { return m_strRelativePath; }

	// 생성자
	cResource();
	virtual ~cResource();
};

