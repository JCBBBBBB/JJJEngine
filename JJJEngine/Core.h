#pragma once
#include "pch.h"
#include "GameObject.h"
#include "InputManager.h"
#include "TimeManager.h"


class Core
{
	public:
		Core();
		~Core();

		void Init(HWND hwnd);
		void Update();
		void Render();

	private:
		HWND m_hwnd;
		HDC m_hdc;

		GameObject m_player;
};


