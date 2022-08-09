#pragma once

#include "CustomDefine.h"
#include "Collider.h"

union COLLIDER_ID
{
	struct
	{
		UINT Left_ID;
		UINT Right_ID;
	};
	ULONGLONG ID;	
};

class cCollisionManager
{
	SINGLETON2(cCollisionManager)

private:
	map<ULONGLONG, bool> m_mapColInfo;		//�浹ü ���� ���� ������ �浹 ����

	UINT m_arrCheck[(UINT)GROUP_TYPE::END]; // �׷찣�� �浹 üũ ���
	//bool m_arrCheck[(UINT)GROUP_TYPE::END][(UINT)GROUP_TYPE::END];

	void CollisionGroupUpdate(GROUP_TYPE _Left, GROUP_TYPE _Right);
	bool IsCollision(cCollider* _Leftcldr, cCollider* _Rightcldr);
	

public:	
	void Init();
	void CheckGroup(GROUP_TYPE _Left, GROUP_TYPE _Right);
	void Reset() {memset(m_arrCheck, 0, sizeof(UINT) * (UINT)GROUP_TYPE::END);};
	//void Reset() { memset(m_arrCheck, false, sizeof(m_arrCheck[0][0]) * (UINT)GROUP_TYPE::END * (UINT)GROUP_TYPE::END); };
	void Update();
};

