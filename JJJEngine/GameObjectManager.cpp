#include "GameObjectManager.h"

GameObjectManager::~GameObjectManager()
{
	Clear();
}

void GameObjectManager::Add(GameObject* gameObject)
{
	if (gameObject == nullptr)
	{
		return;
	}
	
	auto iter = std::find(m_gameObjects.begin(), m_gameObjects.end(), gameObject); // 같은 오브젝트 있는지 체크

	if (iter != m_gameObjects.end()) // 같은 오브젝트 있으면
	{
		return;
	}

	m_gameObjects.push_back(gameObject);
}

void GameObjectManager::Remove(GameObject* gameObject)
{
	if (gameObject == nullptr)
	{
		return;
	}

	auto iter = std::remove(m_gameObjects.begin(), m_gameObjects.end(), gameObject);

	m_gameObjects.erase(iter, m_gameObjects.end());

	delete gameObject;
}

void GameObjectManager::Clear()
{
	for (GameObject* gameObject : m_gameObjects)
	{
		delete gameObject;
	}

	m_gameObjects.clear();
}

