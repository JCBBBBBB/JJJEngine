#pragma once
#include "pch.h"



class Core
{
	public:
		Core();
		~Core();

		void Init(HWND hwnd);
		void Update();
		void Render();

	private:
		RECT m_rect;
		HWND m_hwnd;
		HDC m_hdc;

		HDC m_backHdc;
		HBITMAP m_backBmp;
		
};


