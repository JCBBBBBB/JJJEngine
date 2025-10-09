#include "Missile.h"
#include "TimeManager.h"
#include "GameObjectManager.h"

Missile::Missile() : GameObject(GameObjectType::Missile)
{

}

Missile::~Missile()
{

}

void Missile::Init()
{
	m_stat.speed = 300.f;
	
}

void Missile::Update()
{
	m_pos.y -= m_stat.speed * TimeManager::GetInstance()->GetDeltaTime();

	const std::vector<GameObject*> gameObjects = GameObjectManager::GetInstance()->GetObjects();

	for (auto gameObject : gameObjects)
	{
		if (gameObject == this)
		{
			continue;
		}

		if (gameObject->GetGameObjectType() != GameObjectType::Monster)
		{
			continue;
		}

		Pos p1 = this->GetPos(); // 내 위치
		Pos p2 = gameObject->GetPos(); // 상대 몬스터 위치

		const float difX = p1.x - p2.x;
		const float difY = p1.y - p2.y;
		float dist = sqrt(difX * difX + difY * difY);

		if (dist < 30.f)
		{
			GameObjectManager::GetInstance()->Remove(gameObject);
			GameObjectManager::GetInstance()->Remove(this);
			return;
		}
	}


	if (m_pos.y < 0.f)
	{
		GameObjectManager::GetInstance()->Remove(this);
		return;
	}
}

void Missile::Render(HDC hdc)
{
	HBRUSH redBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 0)); // 블루브러쉬 생성

	HPEN bluePen = (HPEN)CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); // greenPen 생성


	Ellipse(hdc, m_pos.x,  m_pos.y, 50 + m_pos.x, 50 + m_pos.y);

	SelectObject(hdc, redBrush);
	SelectObject(hdc, bluePen);

	DeleteObject(redBrush);
	DeleteObject(bluePen);
}
