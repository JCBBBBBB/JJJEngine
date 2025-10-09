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
	std::vector<std::pair<POINT, POINT>> m_lines; // ��

	bool m_setOrigin = true; // ó������ ��ǥ�� �����
	POINT m_lastPosition = {}; // ������ ��ǥ
};

