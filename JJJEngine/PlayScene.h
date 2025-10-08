#pragma once
#include "pch.h"
#include "Scene.h"


class PlayScene : public Scene
{
public:
	void Init() override;
	void Update() override;
	void Render(HDC hdc) override;


private:
};

