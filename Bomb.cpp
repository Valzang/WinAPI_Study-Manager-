#include "Bomb.h"


// PI == -PI 좌측직선		0	=> 우측 직선
// PI/2 => 아래직선			-PI/2 => 위 직선
// PI/4 => 우측아래대각선		-PI/4 => 우측위 대각선
cBomb::cBomb() : m_Theta((float)(3*PI / -4.f)), m_Dir(Vec2(-2.f,-3.f))
{
	m_Dir.Normalize();
	//CreateCollider();
}

cBomb::~cBomb()
{
}

void cBomb::Update()
{
	Vec2 Pos = GetPos();
	
	// 포물선 시도해본것.
	/*
	double Degree = m_Theta * 180 / PI;
	if (Degree > -270)
	{
		Pos.x += 500.f * cosf(m_Theta) * DELTA_TIME;
		static double test = 0.0;
		test += DELTA_TIME;
		if (test >= 0.01)
		{
			test = 0.0;
			m_Theta -= 0.02;
		}

		if (abs(m_Theta) > 2 * PI) // 2PI == 360도 범위를 안 벗어나게끔 설정.
			m_Theta = m_Theta > 0 ? m_Theta - 2 * PI : m_Theta + 2 * PI;
	}

	Pos.y += 500.f * sinf(m_Theta) * DELTA_TIME;
	*/

	// 각도로 변화
	//Pos.x += 600.f * cosf(m_Theta) * DELTA_TIME;
	//Pos.y += 600.f * sinf(m_Theta) * DELTA_TIME;


	// 벡터로 변화
	Pos.x += 600.f * m_Dir.x * DELTA_TIME;
	Pos.y += 600.f * m_Dir.y * DELTA_TIME;

	m_Dir.y += 0.002f;

	SetPos(Pos);

}

void cBomb::Render(HDC _hdc)
{
	// Rectangle은 예시임
	Vec2 Pos = GetPos();
	Vec2 Scale = GetScale();

	Ellipse(_hdc, (int)(Pos.x - Scale.x / 2.f), (int)(Pos.y - Scale.y / 2.f),
			  (int)(Pos.x + Scale.x / 2.f), (int)(Pos.y + Scale.y / 2.f));

	Component_Render(_hdc);
}
