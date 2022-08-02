#pragma once

#include "CustomDefine.h"
#include "Collider.h"

class cCollisionManager
{
	SINGLETON2(cCollisionManager)

private:
	//충돌체 간의 이전 프레임 충돌 정보

	UINT m_arrCheck[(UINT)GROUP_TYPE::END]; // 그룹간의 충돌 체크 행렬


//	bool m_arrCheck[(UINT)GROUP_TYPE::END][(UINT)GROUP_TYPE::END];
	void CollisionGroupUpdate(GROUP_TYPE _Left, GROUP_TYPE _Right);
	bool IsCollision(cCollider* _Leftcoll, cCollider* _Rightcoll);
	

public:
	cCollisionManager();
	~cCollisionManager();
	void Init();
	void CheckGroup(GROUP_TYPE _Left, GROUP_TYPE _Right);
	void Reset() {memset(m_arrCheck, 0, sizeof(UINT) * (UINT)GROUP_TYPE::END);};
	//void Reset() { memset(m_arrCheck, false, sizeof(m_arrCheck[0][0]) * (UINT)GROUP_TYPE::END * (UINT)GROUP_TYPE::END); };
	void Update();
};

