#include "GameObject.h"

GameObject::GameObject(GameObjectType type) : m_type(type)
{
}

GameObject::~GameObject()
{
}

GameObjectType GameObject::GetGameObjectType()
{
	return m_type;
}

void GameObject::SetPos(Pos pos)
{
	m_pos.x = pos.x;
	m_pos.y = pos.y;
}

Pos GameObject::GetPos()
{
	return m_pos;
}