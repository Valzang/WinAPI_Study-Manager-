#pragma once

#include <Windows.h>
#include <vector>
#include <tchar.h>
#include <string>
#include <cmath>
#include <assert.h>
#include <map>

#pragma comment(lib,"Msimg32.lib")

#define PI 3.1415926535

using namespace std;

#define SINGLETON2(type) public:\
							static type* GetInstance()\
							{\
								static type mgr;\
								return &mgr;\
							}\
						private:\
							type();\
							~type();

#define DELTA_TIME cTimeManager::GetInstance()->GetDT()
#define KEY_CHECK(key, state) cKeyManager::GetInstance()->GetKeyState(key) == state

struct Vec2
{
	float x;
	float y;

	// 생성자 ===================================================
	Vec2(const POINT _pt) : x((float)_pt.x), y((float)_pt.y) {}
	Vec2& operator=(POINT _pt)
	{
		x = (float)_pt.x;
		y = (float)_pt.y;
	}

	Vec2() : x(0.f), y(0.f) {}
	Vec2(float _x, float _y) : x(_x), y(_y) {}
	Vec2(int _x, int _y) : x((float)_x), y((float)_y) {}

	// 생성자 ===================================================
	Vec2& Normalize()
	{
		float fLen = Length();

		assert(fLen != 0.f); // 0이면 오류

		x /= fLen;
		y /= fLen;
		return* this;
	}

	float Length()
	{
		return sqrt(x* x + y * y);
	}
};

enum class GROUP_TYPE
{
	DEFAULT,
	PLAYER,
	MONSTER,
	THING,

	END = 10,
};

enum class SCENE_TYPE
{
	TOOL,
	START,
	STAGE_11,
	STAGE_12,
	STAGE_13,
	STAGE_14,
	STAGE_15,

	END,
};



