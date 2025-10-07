#include "TimeManager.h"


void TimeManager::Init()
{
    QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
    QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));
}

void TimeManager::Update()
{
    UINT64 currentCount;
    QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

    _deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency);
    _prevCount = currentCount;
}