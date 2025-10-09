#pragma once

enum class SceneType // �� ����
{
	None,
	PlayScene, // �÷��� �ϴ� ��
	EditScene,
};

enum class GameObjectType // ���� ������Ʈ ����
{
	None,
	Player,
	Monster,
	Missile,
	
};

enum class KeyType // Ű ����
{
	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M,
	LEFT, RIGHT, DOWN, UP, 
	SPACE,
	LEFT_MOUSE, RIGHT_MOUSE,
	END,
};


enum class KeyState // Ű ��������
{
	NONE,
	PRESSED,
	UP,
	DOWN,
};