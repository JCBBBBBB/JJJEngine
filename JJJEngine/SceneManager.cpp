#include "SceneManager.h"
#include "GameObjectManager.h"
#include "PlayScene.h"
#include "EditScene.h"

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

void SceneManager::Clear()
{
	if (m_currentScene)
	{
		delete m_currentScene;
		m_currentScene = nullptr;
	}
}

void SceneManager::ChangeScene(SceneType sceneType) // �ٲٷ��� �� ����
{
	if (m_sceneType == sceneType) // ���� �� ������ �ٲٷ��� �� ������ ���ٸ�
	{
		return;
	}

	Scene* newScene = nullptr;

	switch (sceneType)
	{
		case SceneType::PlayScene:
			newScene = new PlayScene();
			break;

		case SceneType::EditScene:
			newScene = new EditScene();
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
