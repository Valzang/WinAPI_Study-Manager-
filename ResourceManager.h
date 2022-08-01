#pragma once
#include "CustomDefine.h"
#include "Texture.h"

//class cTexture;

class cResourceManager
{
	SINGLETON2(cResourceManager);
private:
	map<wstring, cTexture*> m_mapTex;

public:
	cTexture* LoadTexture(const wstring& _strKey, const wstring& _strRelativePath);
	cTexture* FindTexture(const wstring& _strKey);

};

