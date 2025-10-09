#include "Monster.h"

Monster::Monster() : GameObject(GameObjectType::Monster)
{

}

Monster::~Monster()
{

}

void Monster::Init()
{
	m_stat.hp = 50;
	m_stat.maxHp = 50;
	m_stat.speed = 10;
}

void Monster::Update()
{

}

void Monster::Render(HDC hdc)
{
	HBRUSH redBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 0)); // 喉风宏矾浆 积己

	HPEN bluePen = (HPEN)CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); // greenPen 积己


	Rectangle(hdc, m_pos.x, m_pos.y, 50 + m_pos.x, 50 + m_pos.y);

	SelectObject(hdc, redBrush);
	SelectObject(hdc, bluePen);

	DeleteObject(redBrush);
	DeleteObject(bluePen);
}
