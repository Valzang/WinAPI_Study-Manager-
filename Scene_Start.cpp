#include "Scene_Start.h"
#include "Player.h"
#include "Monster.h"

#include "Core.h"
#include "CollisionManager.h"


void cScene_Start::Enter()
{
	// Object 추가
	cObject* PlayerObj = new cPlayer;

	// Object 위치, 크기 설정
	PlayerObj->SetPos(Vec2 { 640.f, 384.f });
	PlayerObj->SetScale(Vec2 {100.f, 100.f});
	AddObject(PlayerObj, GROUP_TYPE::PLAYER);


	// 몬스터 배치
	int MonCount = 5;
	float MoveDist = 25.f;
	float ObjectScale = 50.f;

	Vec2 Resolution = cCore::GetInstance()->GetResolution();
	float temp = (Resolution.x - ((MoveDist+ ObjectScale/2.f) * 2)) / (float)(MonCount-1);

	//Monster Object 추가
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

	// 충돌 지정
	// 플레이어 그룹과 몬스터 그룹 간의 충돌 체크
	cCollisionManager::GetInstance()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);

}

void cScene_Start::Exit() // 다른 씬으로 전환할 때
{
	cCollisionManager::GetInstance()->Reset();
}
