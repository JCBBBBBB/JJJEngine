#include "GameObject.h"
#include "InputManager.h"
#include "TimeManager.h"

	GameObject::GameObject() : m_x(0), m_y(0)
	{

	}

	GameObject::~GameObject()
	{

	}

	void GameObject::Init()
	{

	}

	void GameObject::Update()
	{
		float _speed = 1000.0f;

		if (InputManager::GetInstance()->GetKey(KeyType::W))
		{
			m_y -= 0.1f * _speed * TimeManager::GetInstance()->GetDeltaTime();
		}

		if (InputManager::GetInstance()->GetKey(KeyType::A))
		{
			m_x -= 0.1f * _speed * TimeManager::GetInstance()->GetDeltaTime();
		}

		if (InputManager::GetInstance()->GetKey(KeyType::S))
		{
			m_y += 0.1f * _speed * TimeManager::GetInstance()->GetDeltaTime();
		}

		if (InputManager::GetInstance()->GetKey(KeyType::D))
		{
			m_x += 0.1f * _speed * TimeManager::GetInstance()->GetDeltaTime();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		HBRUSH redBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 0)); // 喉风宏矾浆 积己

		HPEN bluePen = (HPEN)CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); // greenPen 积己


		Rectangle(hdc, 100 + m_x, 100 + m_y, 200 + m_x, 200 + m_y);

		SelectObject(hdc, redBrush);
		SelectObject(hdc, bluePen);

		DeleteObject(redBrush);
		DeleteObject(bluePen);
	}
