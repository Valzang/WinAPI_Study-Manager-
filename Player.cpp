#include "Player.h"

#include "Bomb.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Collider.h"

cPlayer::cPlayer()
{
	// Texture �ε��ϱ�
	m_Tex = cResourceManager::GetInstance()->LoadTexture(L"PlayerTexture", L"texture\\temmie.bmp");
	CreateCollider();

	GetCollider()->SetScale(Vec2(m_Tex->Width(), m_Tex->Height()));
	
}

cPlayer::~cPlayer()
{

}

void cPlayer::Update()
{
	Vec2 Pos = GetPos();

	// DELTA_TIME���� �ð�����ȭ �ؼ� �̵�

	if (KEY_CHECK(KEY::I, KEY_STATE::HOLD))
	{
		Pos.y -= 200.f * DELTA_TIME;
	}
	if (KEY_CHECK(KEY::K, KEY_STATE::HOLD))
	{
		Pos.y += 200.f * DELTA_TIME;
	}
	if (KEY_CHECK(KEY::J, KEY_STATE::HOLD))
	{
		Pos.x -= 200.f * DELTA_TIME;
	}
	if (KEY_CHECK(KEY::L, KEY_STATE::HOLD))
	{
		Pos.x += 200.f * DELTA_TIME;
	}
	

	if (KEY_CHECK(KEY::A, KEY_STATE::DOWN))
	{
		CreateBomb();
	}
	SetPos(Pos);
}

void cPlayer::Render(HDC _dc)
{
	int iWidth = (int)m_Tex->Width();
	int iHeight = (int)m_Tex->Height();

	Vec2 Pos = GetPos();

	//BitBlt(_dc,
	//	   (int)(Pos.x - (float)(iWidth / 2)), (int)(Pos.y - (float)(iHeight / 2)),
	//	   iWidth, iHeight, m_Tex->GetDC(), 0, 0, SRCCOPY);

	TransparentBlt(_dc,
		   (int)(Pos.x - (float)(iWidth / 2)), (int)(Pos.y - (float)(iHeight / 2)),
		   iWidth, iHeight, m_Tex->GetDC(), 0, 0, iWidth, iHeight, RGB(255,0,255));

	Component_Render(_dc);

}

void cPlayer::CreateBomb()
{
	Vec2 bomb_Pos = GetPos();
	bomb_Pos.y -= GetScale().y / 2.f;

	// ��ź ������Ʈ
	cBomb* bomb = new cBomb;
	bomb->SetPos(bomb_Pos);
	bomb->SetScale(Vec2(25.f, 25.f));
	//bomb->SetDirection(true);

	cScene* curScene = cSceneManager::GetInstance()->GetCurScene();
	curScene->AddObject(bomb, GROUP_TYPE::DEFAULT);
}
