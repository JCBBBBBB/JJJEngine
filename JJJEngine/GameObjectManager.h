#pragma once
#include "pch.h"
#include "GameObject.h"


class GameObjectManager
{
	SINGLETONE(GameObjectManager);

public:
	~GameObjectManager();

	void Add(GameObject* gameObject); // 게임오브젝트 추가
	void Remove(GameObject* gameObject); // 게임오브젝트 제거
	void Clear();

	const std::vector<GameObject*>& GetObjects(); // 게임오브젝트들이 있는 벡터 가져온다

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