#pragma once
#include "pch.h"


class GameObject
{
	public:
		GameObject();
		~GameObject();

		void Init();
		void Update();
		void Render(HDC hdc);

	private:
		float m_x, m_y;
};

