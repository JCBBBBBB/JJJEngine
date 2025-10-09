#pragma once

enum class SceneType // 씬 종류
{
	None,
	PlayScene, // 플레이 하는 씬
	EditScene,
};

enum class GameObjectType // 게임 오브젝트 종류
{
	None,
	Player,
	Monster,
	Missile,
	
};

enum class KeyType // 키 종류
{
	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M,
	LEFT, RIGHT, DOWN, UP, 
	SPACE,
	LEFT_MOUSE, RIGHT_MOUSE,
	END,
};


enum class KeyState // 키 눌림상태
{
	NONE,
	PRESSED,
	UP,
	DOWN,
};