#pragma once
#include "Resources.h"

class cTexture : public cResource
{
private:
	HDC m_dc;
	HBITMAP m_hBit;

public:
	// ������
	cTexture();
	virtual ~cTexture();

	void Load(const wstring& _strFilePath);


};

