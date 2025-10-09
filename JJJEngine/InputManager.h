#pragma once
#include "pch.h"


class InputManager
{
	SINGLETONE(InputManager);


public:
	void Init(HWND hwnd);
	void Update();
	
	bool GetKey(KeyType keytype);
	bool GetKeyDown(KeyType keytype);
	bool GetKeyUp(KeyType keytype);

	POINT GetMousePos() const;

private:
	std::vector<Key> m_keys;
	POINT m_mousePos = {};
	HWND m_hwnd = nullptr;
};

