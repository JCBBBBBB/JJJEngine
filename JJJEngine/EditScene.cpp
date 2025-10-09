#include "EditScene.h"
#include "InputManager.h"

EditScene::EditScene()
{
}

EditScene::~EditScene()
{
}

void EditScene::Init()
{
}

void EditScene::Update()
{
	if (InputManager::GetInstance()->GetKeyDown(KeyType::LEFT_MOUSE))
	{
		POINT mousePos = InputManager::GetInstance()->GetMousePos();

		if (m_setOrigin)
		{
			m_lastPosition = mousePos;
			m_setOrigin = false;
		}
		else
		{
			m_lines.push_back(std::make_pair(m_lastPosition, mousePos));
			m_lastPosition = mousePos;
		}
	}

	if (InputManager::GetInstance()->GetKeyDown(KeyType::RIGHT_MOUSE))
	{
		m_setOrigin = true;
	}
}

void EditScene::Render(HDC hdc)
{
	for (auto& line : m_lines)
	{
		POINT p1 = line.first;
		POINT p2 = line.second;

		Pos pos1;
		pos1.x = (float)p1.x;
		pos1.y = (float)p1.y;

		Pos pos2;
		pos2.x = (float)p2.x;
		pos2.y = (float)p2.y;

		::MoveToEx(hdc, static_cast<INT32>(pos1.x), static_cast<INT32>(pos1.y), nullptr);
		::LineTo(hdc, static_cast<INT32>(pos2.x), static_cast<INT32>(pos2.y));
	}
}
