#include "PlayScene.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "GameObjectManager.h"
#include "Player.h"
#include "Monster.h"

void PlayScene::Init()
{
	Player* player = GameObjectManager::GetInstance()->CreateGameObjects<Player>();
	player->SetPos(Pos{ 300,400 });
	GameObjectManager::GetInstance()->Add(player);

	for (int i = 0; i < 5; i++)
	{
		Monster* monster = GameObjectManager::GetInstance()->CreateGameObjects<Monster>();
		monster->SetPos(Pos{ 50.f + i * 150.f, 50.f});
		GameObjectManager::GetInstance()->Add(monster);
	}
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
