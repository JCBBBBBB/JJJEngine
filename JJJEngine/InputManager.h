#pragma once
#include "pch.h"


enum class KeyType
{
	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M,
	LEFT, RIGHT, DOWN, UP,
	END,
};



enum class KeyState
{
	NONE,
	PRESSED,
	UP,
	DOWN,
};

struct Key
{
	KeyType keyType;
	KeyState keyState;
	bool isPressed;
};

class InputManager
{
	SINGLETONE(InputManager);


public:
	void Init();
	void Update();
	
	bool GetKey(KeyType keytype);
	bool GetKeyDown(KeyType keytype);
	bool GetKeyUp(KeyType keytype);

private:
	std::vector<Key> m_keys;
};

