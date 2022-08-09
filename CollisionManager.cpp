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

	UINT iRow = (UINT)_Left < (UINT)_Right ? (UINT)_Left : (UINT)_Right;
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

	map<ULONGLONG, bool>::iterator iter;

	for (UINT i = 0; i < vecLeft.size(); ++i)
	{
		cCollider* LeftCollider = vecLeft[i]->GetCollider();
		// 충돌체 없는 경우
		if (LeftCollider == nullptr)
			continue;
		for (UINT j = 0; j < vecRight.size(); ++j)
		{			
			// 충돌체가 없거나, 자기 자신과의 충돌인 경우
			if (vecRight[j]->GetCollider() == nullptr || vecLeft[i] == vecRight[j])
				continue;

			cCollider* RightCollider = vecRight[j]->GetCollider();

			// 두 충돌체 조합으로 아이디 생성
			COLLIDER_ID ID;
			ID.Left_ID = LeftCollider->GetID();
			ID.Right_ID = RightCollider->GetID();

			iter = m_mapColInfo.find(ID.ID);

			// 충돌 정보에 없는 경우 새로 등록
			if (iter == m_mapColInfo.end())
			{
				m_mapColInfo.insert(make_pair(ID.ID, false));
				iter = m_mapColInfo.find(ID.ID);
			}

			
			// 충돌하고 있는 경우
			if (IsCollision(LeftCollider, RightCollider))
			{
				// 현재 충돌 중이고 이전에도 충돌
				if (iter->second)
				{
					LeftCollider->OnCollision(RightCollider);
					RightCollider->OnCollision(LeftCollider);
				}
				// 현재 충돌 중인데, 이전에는 충돌 X
				else
				{
					LeftCollider->OnCollisionEnter(RightCollider);
					RightCollider->OnCollisionEnter(LeftCollider);
					iter->second = true;
				}
			}
			else
			{
				// 현재는 충돌 X, 이전에는 충돌 O
				if (iter->second)
				{
					LeftCollider->OnCollisionExit(RightCollider);
					RightCollider->OnCollisionExit(LeftCollider);
					iter->second = false;
				}
			}
		}
	}


}

bool cCollisionManager::IsCollision(cCollider* _Leftcldr, cCollider* _Rightcldr)
{
	Vec2 LeftPos = _Leftcldr->GetFinalPos();
	Vec2 LeftScale = _Leftcldr->GetScale();

	Vec2 RightPos = _Rightcldr->GetFinalPos();
	Vec2 RightScale = _Rightcldr->GetScale();

	if ((abs(RightPos.x - LeftPos.x) < (LeftScale.x + RightScale.x) / 2.f)
		&& (abs(RightPos.y - LeftPos.y) < (LeftScale.y + RightScale.y) / 2.f))
	{
		return true;
	}
	return false;
}

