#include "Scene_Start.h"
#include "Player.h"
#include "Monster.h"

#include "Core.h"
#include "CollisionManager.h"


void cScene_Start::Enter()
{
	// Object �߰�
	cObject* PlayerObj = new cPlayer;

	// Object ��ġ, ũ�� ����
	PlayerObj->SetPos(Vec2 { 640.f, 384.f });
	PlayerObj->SetScale(Vec2 {100.f, 100.f});
	AddObject(PlayerObj, GROUP_TYPE::PLAYER);


	// ���� ��ġ
	int MonCount = 5;
	float MoveDist = 25.f;
	float ObjectScale = 50.f;

	Vec2 Resolution = cCore::GetInstance()->GetResolution();
	float temp = (Resolution.x - ((MoveDist+ ObjectScale/2.f) * 2)) / (float)(MonCount-1);

	//Monster Object �߰�
	cMonster* MonsterObj = nullptr;
	for (int i = 0; i < MonCount; ++i)
	{
		MonsterObj = new cMonster;
		MonsterObj->SetPos(Vec2 { (MoveDist + ObjectScale / 2.f) + temp*(float)i, 50.f });
		MonsterObj->SetCenterPos(MonsterObj->GetPos());
		MonsterObj->SetMaxDist(MoveDist);
		MonsterObj->SetScale(Vec2 { ObjectScale, ObjectScale });
		AddObject(MonsterObj, GROUP_TYPE::MONSTER);		
	}

	// �浹 ����
	// �÷��̾� �׷�� ���� �׷� ���� �浹 üũ
	cCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);

}

void cScene_Start::Exit() // �ٸ� ������ ��ȯ�� ��
{
	cCollisionManager::GetInstance()->Reset();
}
