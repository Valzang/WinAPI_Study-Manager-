#pragma once
#include "Resources.h"

class cTexture : public cResource
{
private:
	HDC m_dc;
	HBITMAP m_hBit;
	BITMAP m_Info;

public:
	// »ý¼ºÀÚ
	cTexture();
	virtual ~cTexture();

	UINT Width() { return m_Info.bmWidth; }
	UINT Height() { return m_Info.bmHeight; }

	HDC GetDC() { return m_dc; }

	void Load(const wstring& _strFilePath);


};

