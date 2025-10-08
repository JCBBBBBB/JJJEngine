#pragma once
#include "pch.h"

class TimeManager
{
	SINGLETONE(TimeManager);

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	float GetDeltaTime() { return m_deltaTime; }
private:
	float m_deltaTime = 0.0f;
	UINT64 m_frequency = 0;
	UINT64 m_prevCount = 0;
};

