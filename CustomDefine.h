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
	Vec2() : x(0.f), y(0.f) {}

	template <typename T>
	Vec2(T _x, T _y) : x((float)_x), y((float)_y) {}
	//Vec2(int _x, int _y) : x((float)_x), y((float)_y) {}


	// 연산자 ===================================================

	Vec2& operator=(POINT _pt)
	{
		x = (float)_pt.x;
		y = (float)_pt.y;
	}

	Vec2& operator=(Vec2 _Other)
	{
		x = (float)_Other.x;
		y = (float)_Other.y;
		return *this;
	}

	Vec2& operator+(Vec2 _Other)
	{
		x += _Other.x;
		y += _Other.y;
		return *this;
	}

	Vec2& operator-(Vec2 _Other)
	{
		x -= _Other.x;
		y -= _Other.y;
		return *this;
	}

	Vec2& operator*(Vec2 _Other)
	{
		x *= _Other.x;
		y *= _Other.y;
		return *this;
	}

	Vec2& operator/(Vec2 _Other)
	{
		assert(!(_Other.x == 0.f || _Other.y == 0.f));

		x /= _Other.x;
		y /= _Other.y;
		return *this;
	}



	// ========================================================
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

enum class BRUSH_TYPE
{
	HOLLOW,
	END,	
};

enum class PEN_TYPE
{
	RED,
	GREEN,
	BLUE,
	END,
};

