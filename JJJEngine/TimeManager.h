#pragma once
#include "Defines.h"
#include "pch.h"

class TimeManager
{
	SINGLETONE(TimeManager);

public:
	void Init();
	void Update();
	float GetDeltaTime() { return _deltaTime; }
private:
	float _deltaTime = 0.0f;
	UINT64 _frequency = 0;
	UINT64 _prevCount = 0;
};

