#include "PlayScene.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "GameObjectManager.h"
#include "Player.h"

void PlayScene::Init()
{
	Player* player = GameObjectManager::GetInstance()->CreateGameObjects<Player>();
	player->SetPos(Pos{ 300,400 });
	GameObjectManager::GetInstance()->Add(player);
}

void PlayScene::Update()
{
	const std::vector<GameObject*> gameObjects = GameObjectManager::GetInstance()->GetObjects();

	for (GameObject* gameObject : gameObjects)
	{
		gameObject->Update();
	}
}

void PlayScene::Render(HDC hdc)
{
	const std::vector<GameObject*> gameObjects = GameObjectManager::GetInstance()->GetObjects();

	for (GameObject* gameObject : gameObjects)
	{
		gameObject->Render(hdc);
	}
}
