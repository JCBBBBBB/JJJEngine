#pragma once
#include "pch.h"

class GameObject
{
public:
	GameObject(GameObjectType type);
	virtual ~GameObject();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	GameObjectType GetGameObjectType() const
	{
		return m_type;
	}

	void SetPos(Pos pos)
	{
		m_pos.x = pos.x;
		m_pos.y = pos.y;
	}

	Pos GetPos() const
	{
		return m_pos;
	}

protected:
	GameObjectType m_type = GameObjectType::None;
	Stat m_stat = {};
	Pos m_pos = {};
};

