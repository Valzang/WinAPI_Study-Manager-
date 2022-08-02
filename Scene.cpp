#include "Scene.h"

cScene::~cScene()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (UINT j = 0; j < m_arr_obj[i].size(); ++j)
		{
			// m_arr_obj[i] �׷� ������ j ��ü ����
			delete m_arr_obj[i][j];
		}
	}
	// ������ ������ ���Ұ� �������ٸ�
	// �Ҹ��� ��ü���� ���� ��ü�� ������
}

void cScene::Update()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (UINT j = 0; j < m_arr_obj[i].size(); ++j)
		{
			m_arr_obj[i][j]->Update();
		}
	}
}

void cScene::FinalUpdate()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (UINT j = 0; j < m_arr_obj[i].size(); ++j)
		{
			m_arr_obj[i][j]->FinalUpdate();
		}
	}
}

void cScene::Render(HDC _hdc)
{
	int iWidth = (int)m_Tex->Width();
	int iHeight = (int)m_Tex->Height();

	//Vec2 Pos = GetPos();

	//BitBlt(_dc,
	//	   (int)(Pos.x - (float)(iWidth / 2)), (int)(Pos.y - (float)(iHeight / 2)),
	//	   iWidth, iHeight, m_Tex->GetDC(), 0, 0, SRCCOPY);

	TransparentBlt(_hdc,
				   0, 0,
				   iWidth, iHeight, m_Tex->GetDC(), 0, 0, iWidth, iHeight, RGB(255, 0, 255));

	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (UINT j = 0; j < m_arr_obj[i].size(); ++j)
		{
			m_arr_obj[i][j]->Render(_hdc);
		}
	}
}
