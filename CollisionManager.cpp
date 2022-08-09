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

	// �� ���� ���� �׷� Ÿ���� ������
	// ū ���� ��(=��Ʈ ����)�� ���

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
		// �浹ü ���� ���
		if (LeftCollider == nullptr)
			continue;
		for (UINT j = 0; j < vecRight.size(); ++j)
		{			
			// �浹ü�� ���ų�, �ڱ� �ڽŰ��� �浹�� ���
			if (vecRight[j]->GetCollider() == nullptr || vecLeft[i] == vecRight[j])
				continue;

			cCollider* RightCollider = vecRight[j]->GetCollider();

			// �� �浹ü �������� ���̵� ����
			COLLIDER_ID ID;
			ID.Left_ID = LeftCollider->GetID();
			ID.Right_ID = RightCollider->GetID();

			iter = m_mapColInfo.find(ID.ID);

			// �浹 ������ ���� ��� ���� ���
			if (iter == m_mapColInfo.end())
			{
				m_mapColInfo.insert(make_pair(ID.ID, false));
				iter = m_mapColInfo.find(ID.ID);
			}

			
			// �浹�ϰ� �ִ� ���
			if (IsCollision(LeftCollider, RightCollider))
			{
				// ���� �浹 ���̰� �������� �浹
				if (iter->second)
				{
					LeftCollider->OnCollision(RightCollider);
					RightCollider->OnCollision(LeftCollider);
				}
				// ���� �浹 ���ε�, �������� �浹 X
				else
				{
					LeftCollider->OnCollisionEnter(RightCollider);
					RightCollider->OnCollisionEnter(LeftCollider);
					iter->second = true;
				}
			}
			else
			{
				// ����� �浹 X, �������� �浹 O
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

