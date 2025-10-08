#include "Player.h"
#include "GameObject.h"
#include "InputManager.h"
#include "TimeManager.h"

Player::Player() : GameObject(GameObjectType::Player)
{

}

Player::~Player()
{

}

void Player::Init()
{
	m_stat.hp = 100;
	m_stat.maxHp = 100;
	m_stat.speed = 100;

	m_pos.x = 400;
	m_pos.y = 500;
}

void Player::Update()
{
	float _speed = 1000.0f;

	if (InputManager::GetInstance()->GetKey(KeyType::W))
	{
		m_pos.y -= 0.1f * _speed * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (InputManager::GetInstance()->GetKey(KeyType::A))
	{
		m_pos.x -= 0.1f * _speed * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (InputManager::GetInstance()->GetKey(KeyType::S))
	{
		m_pos.y += 0.1f * _speed * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (InputManager::GetInstance()->GetKey(KeyType::D))
	{
		m_pos.x += 0.1f * _speed * TimeManager::GetInstance()->GetDeltaTime();
	}
}

void Player::Render(HDC hdc)
{
	HBRUSH redBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 0)); // 喉风宏矾浆 积己

	HPEN bluePen = (HPEN)CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); // greenPen 积己


	Rectangle(hdc, 100 + m_pos.x, 100 + m_pos.y, 200 + m_pos.x, 200 + m_pos.y);

	SelectObject(hdc, redBrush);
	SelectObject(hdc, bluePen);

	DeleteObject(redBrush);
	DeleteObject(bluePen);
}
