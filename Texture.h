#pragma once
#include "Resources.h"

class cTexture : public cResource
{
private:
	HDC m_dc;
	HBITMAP m_hBit;

public:
	// »ý¼ºÀÚ
	cTexture();
	virtual ~cTexture();

	void Load(const wstring& _strFilePath);


};

