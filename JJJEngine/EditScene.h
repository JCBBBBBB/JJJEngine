#pragma once
#include "pch.h"
#include "Scene.h"

class EditScene : public Scene
{
public:
	EditScene();
	virtual ~EditScene() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	std::vector<std::pair<POINT, POINT>> m_lines; // 선

	bool m_setOrigin = true; // 처음으로 좌표를 찍는지
	POINT m_lastPosition = {}; // 마지막 좌표
};

