#include "TimeManager.h"


void TimeManager::Init()
{
    QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&m_frequency));
    QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&m_prevCount));
}

void TimeManager::Update()
{
    UINT64 currentCount;
    QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

    m_deltaTime = (currentCount - m_prevCount) / static_cast<float>(m_frequency);
    m_prevCount = currentCount;
}

void TimeManager::Render(HDC hdc)
{
    float time = 0.0f;
    time += m_deltaTime;

    float fps = 1.0f / m_deltaTime;

    wchar_t str[50] = L"";
    swprintf_s(str, 50, L"FPS : %d", (int)fps);
    int len = wcsnlen_s(str, 50);


    TextOut(hdc, 0, 0, str, len);

}