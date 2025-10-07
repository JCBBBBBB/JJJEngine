#include "Core.h"


Core::Core()
{

}

Core::~Core()
{

}

void Core::Init(HWND hwnd)
{
	m_hwnd = hwnd;
	m_hdc = GetDC(m_hwnd);

	TimeManager::GetInstance()->Init();
	InputManager::GetInstance()->Init();
}

void Core::Update()
{
	TimeManager::GetInstance()->Update();
	InputManager::GetInstance()->Update();
	m_player.Update();
}

void Core::Render()
{
	m_player.Render(m_hdc);
}
