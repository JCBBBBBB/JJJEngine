#pragma once
#include "pch.h"
#include "Scene.h"


class SceneManager
{
	SINGLETONE(SceneManager);

public:
	void Init();
	void Update();
	void Render(HDC hdc);

	void Clear();
	void ChangeScene(SceneType sceneType);


private:
	Scene* m_currentScene;
	SceneType m_sceneType = SceneType::None;
};

