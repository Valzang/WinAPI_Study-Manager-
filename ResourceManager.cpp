#include "ResourceManager.h"

#include "PathManager.h"

cResourceManager::cResourceManager()
{

}

cResourceManager::~cResourceManager()
{
	map < wstring, cTexture*>::iterator iter = m_mapTex.begin();
	for (; iter != m_mapTex.end(); ++iter)
	{
		delete iter->second;
	}
}

cTexture* cResourceManager::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{
	cTexture* Tex = FindTexture(_strKey);
	if (Tex != nullptr)
		return Tex;

	wstring strFilePath = cPathManager::GetInstance()->GetContentPath();
	strFilePath += _strRelativePath;

	Tex = new cTexture;
	Tex->Load(strFilePath);
	Tex->SetKey(_strKey);
	Tex->SetRelativePath(_strRelativePath);

	m_mapTex.insert(make_pair(_strKey, Tex));

	return Tex;
}

cTexture* cResourceManager::FindTexture(const wstring& _strKey)
{
	map<wstring, cTexture*> ::iterator iter = m_mapTex.find(_strKey);
	if (iter == m_mapTex.end()) // 못찾았으면 end를 가리킴
		return nullptr;

	return iter->second;
	
}