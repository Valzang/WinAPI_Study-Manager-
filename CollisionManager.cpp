#include "CollisionManager.h"
#include "SceneManager.h"
#include "Scene.h"



cCollisionManager::cCollisionManager() : m_arrCheck {}
{
}

cCollisionManager::~cCollisionManager()
{
}

void cCollisionManager::Init()
{
}

void cCollisionManager::CheckGroup(GROUP_TYPE _Left, GROUP_TYPE _Right)
{

	// 더 작은 값의 그룹 타입을 행으로
	// 큰 값을 열(=비트 단위)로 사용

	UINT iRow = (UINT)_Left < (UINT)_Left ? (UINT)_Left : (UINT)_Right;
	UINT iCol = iRow == (UINT)_Left ? (UINT)_Right : (UINT)_Left;
	
	if (m_arrCheck[iRow] & (1 << iCol))
		m_arrCheck[iRow] &= ~(1 << iCol);
	else
		m_arrCheck[iRow] |= (1 << iCol);
	//m_arrCheck[(UINT)_Left][(UINT)_Right] = true;
	//m_arrCheck[(UINT)_Right][(UINT)_Left] = true;

}


void cCollisionManager::Update()
{/*
	for (UINT row = 0; row < (UINT)GROUP_TYPE::END; ++row)
	{
		for (UINT col = row; col < (UINT)GROUP_TYPE::END; ++col)
		{
			if (m_arrCheck[row][col])
			{
				CollisionGroupUpdate((GROUP_TYPE)row, (GROUP_TYPE)col);
			}
		}
	}
	*/
	for (UINT row = 0; row < (UINT)GROUP_TYPE::END; ++row)
	{
		for (UINT col = row; col < (UINT)GROUP_TYPE::END; ++col)
		{
			if (m_arrCheck[row] & (1 << col))
			{
				CollisionGroupUpdate((GROUP_TYPE)row, (GROUP_TYPE)col);
			}
		}
	}
}

void cCollisionManager::CollisionGroupUpdate(GROUP_TYPE _Left, GROUP_TYPE _Right)
{
	cScene* CurScene = cSceneManager::GetInstance()->GetCurScene();

	const vector<cObject*>& vecLeft = CurScene->GetGroupObject(_Left);
	const vector<cObject*>& vecRight = CurScene->GetGroupObject(_Right);

	for (UINT i = 0; i < vecLeft.size(); ++i)
	{
		// 충돌체 없는 경우
		if (vecLeft[i]->GetCollider() == nullptr)
			continue;
		for (UINT j = 0; j < vecRight.size(); ++j)
		{			
			// 충돌체가 없거나, 자기 자신인 경우
			if (vecRight[j]->GetCollider() == nullptr
				|| vecLeft[i] == vecRight[j])
				continue;
			
			// 충돌하고 있는 경우
			if (IsCollision(vecLeft[i]->GetCollider(), vecRight[j]->GetCollider()))
			{

			}
		}
	}


}

bool cCollisionManager::IsCollision(cCollider* _Leftcoll, cCollider* _Rightcoll)
{
	return false;
}

