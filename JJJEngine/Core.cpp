#include "Core.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "SceneManager.h"

Core::Core()
{

}

Core::~Core()
{
	SceneManager::GetInstance()->Clear();
}

void Core::Init(HWND hwnd)
{
	m_hwnd = hwnd;
	m_hdc = GetDC(m_hwnd);

	GetClientRect(m_hwnd, &m_rect);

	m_backHdc = CreateCompatibleDC(m_hdc);
	m_backBmp = CreateCompatibleBitmap(m_hdc, m_rect.right, m_rect.bottom);
	HBITMAP prevBmp = (HBITMAP)SelectObject(m_backHdc, m_backBmp);
	DeleteObject(prevBmp);

	TimeManager::GetInstance()->Init();
	InputManager::GetInstance()->Init();
	SceneManager::GetInstance()->Init();

	SceneManager::GetInstance()->ChangeScene(SceneType::PlayScene);
}

void Core::Update()
{
	TimeManager::GetInstance()->Update();
	InputManager::GetInstance()->Update();
	SceneManager::GetInstance()->Update();
}

void Core::Render()
{
	TimeManager::GetInstance()->Render(m_backHdc);
	SceneManager::GetInstance()->Render(m_backHdc);
	
	BitBlt(m_hdc, 0, 0, m_rect.right, m_rect.bottom, m_backHdc, 0, 0, SRCCOPY);
	PatBlt(m_backHdc, 0, 0, m_rect.right, m_rect.bottom, WHITENESS);
}
