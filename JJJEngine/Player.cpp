#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "GameObjectManager.h"
#include "Missile.h"

Player::Player() : GameObject(GameObjectType::Player)
{
	
}

Player::~Player()
{

}

void Player::Init() // 플레이어의 스탯, 위치 초기화
{
	m_stat.hp = 100;
	m_stat.maxHp = 100;
	m_stat.speed = 100;

	m_pos.x = 400;
	m_pos.y = 500;
}

void Player::Update() // 키 로직
{
	float _speed = 1000.0f;

	if (InputManager::GetInstance()->GetKey(KeyType::UP))
	{
		m_pos.y -= 0.1f * _speed * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (InputManager::GetInstance()->GetKey(KeyType::LEFT))
	{
		m_pos.x -= 0.1f * _speed * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (InputManager::GetInstance()->GetKey(KeyType::DOWN))
	{
		m_pos.y += 0.1f * _speed * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (InputManager::GetInstance()->GetKey(KeyType::RIGHT))
	{
		m_pos.x += 0.1f * _speed * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (InputManager::GetInstance()->GetKeyDown(KeyType::SPACE))
	{
		Missile* missile = GameObjectManager::GetInstance()->CreateGameObjects<Missile>();
		missile->SetPos({m_pos.x + 25, m_pos.y - 40});
		GameObjectManager::GetInstance()->Add(missile);
	}
}

void Player::Render(HDC hdc) // 플레이어 그려준다
{
	HBRUSH redBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 0)); // 블루브러쉬 생성

	HPEN bluePen = (HPEN)CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); // greenPen 생성


	Rectangle(hdc, m_pos.x, m_pos.y, 100 + m_pos.x, 100 + m_pos.y);

	SelectObject(hdc, redBrush);
	SelectObject(hdc, bluePen);

	DeleteObject(redBrush);
	DeleteObject(bluePen);
}
