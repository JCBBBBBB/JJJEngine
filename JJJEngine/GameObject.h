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

	GameObjectType GetGameObjectType();

	void SetPos(Pos pos);
	Pos GetPos();

protected:
	GameObjectType m_type = GameObjectType::None;
	Stat m_stat = {};
	Pos m_pos = {};
};

