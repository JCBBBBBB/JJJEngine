#include "SceneManager.h"
#include "GameObjectManager.h"
#include "PlayScene.h"

void SceneManager::Init()
{

}

void SceneManager::Update()
{
	if (m_currentScene)
	{
		m_currentScene->Update();
	}
}

void SceneManager::Render(HDC hdc)
{
	if (m_currentScene)
	{
		m_currentScene->Render(hdc);
	}
}

GameObjectManager::~GameObjectManager()
{
}

void GameObjectManager::Add(GameObject* gameObject)
{
}

void GameObjectManager::Remove(GameObject* gameObject)
{
}

void SceneManager::Clear()
{
	if (m_currentScene)
	{
		delete m_currentScene;
		m_currentScene = nullptr;
	}
}

void SceneManager::ChangeScene(SceneType sceneType)
{
	if (m_sceneType == sceneType)
	{
		return;
	}

	Scene* newScene = nullptr;

	switch (sceneType)
	{
		case SceneType::PlayScene:
			newScene = new PlayScene();
			break;
	}

	if (m_currentScene)
	{
		delete m_currentScene;
		m_currentScene = nullptr;
	}

	m_currentScene = newScene;
	m_sceneType = sceneType;

	newScene->Init();

}
