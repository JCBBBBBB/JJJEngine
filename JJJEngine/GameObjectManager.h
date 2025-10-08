#pragma once
#include "pch.h"
#include "GameObject.h"


class GameObjectManager
{
	SINGLETONE(GameObjectManager);

public:
	~GameObjectManager();

	void Add(GameObject* gameObject);
	void Remove(GameObject* gameObject);
	void Clear();

	const std::vector<GameObject*>& GetObjects()
	{
		return m_gameObjects;
	}

	template <typename T>
	T* CreateGameObjects()
	{
		static_assert(std::is_convertible_v<T*, GameObject*>);

		T* gameObject = new T();
		gameObject->Init();

		return gameObject;
	}

private:
	std::vector<GameObject*> m_gameObjects;
};