#pragma once
#include "Scene.h"
#include "ResourceManager.h"


class cScene_Start : public cScene
{
private:

public:
	cScene_Start() { m_Tex = cResourceManager::GetInstance()->LoadTexture(L"BGTexture", L"texture\\Scene1.bmp"); };
	virtual ~cScene_Start() {  };

	virtual void Enter();
	virtual void Exit();

};

