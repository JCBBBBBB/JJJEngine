#include "InputManager.h"

int ASCII[(UINT)KeyType::END] =
{
	'Q','W','E','R','T','Y','U','I','O','P',
	'A','S','D','F','G','H','J','K','L',
	'Z','X','C','V','B','N','M',
	VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP, VK_SPACE,
	VK_LBUTTON, VK_RBUTTON,
};

void InputManager::Init(HWND hwnd)
{
	m_hwnd = hwnd;

	for (UINT i = 0; i < (UINT)KeyType::END; i++)
	{
		Key key = {};
		key.isPressed = false;
		key.keyType = (KeyType)i;
		key.keyState = KeyState::NONE;

		m_keys.push_back(key);
	}

}

void InputManager::Update()
{
	std::for_each(m_keys.begin(), m_keys.end(), [](Key& key) -> void
		{

			if (GetAsyncKeyState(ASCII[(UINT)key.keyType]) & 0x8000) // � Ű�� ������ ��
			{
				if (key.isPressed) // ���� ���� ������
				{
					key.keyState = KeyState::PRESSED;
				}
				else // ���� ���� �����ʰ� ���� ��������
				{
					key.keyState = KeyState::DOWN;
				}

				key.isPressed = true;
			}
			else // � Ű�� �ȴ����� ��
			{
				if (key.isPressed) // ���� ���� ������
				{
					key.keyState = KeyState::UP;
				}
				else // ���� �� ���� ������
				{
					key.keyState = KeyState::NONE;
				}

				key.isPressed = false;
			}
	});

	GetCursorPos(&m_mousePos);
	ScreenToClient(m_hwnd, &m_mousePos);
}



bool InputManager::GetKey(KeyType keytype)
{
	return m_keys[(UINT)keytype].keyState == KeyState::PRESSED;
}

bool InputManager::GetKeyDown(KeyType keytype)
{
	return m_keys[(UINT)keytype].keyState == KeyState::DOWN;
}

bool InputManager::GetKeyUp(KeyType keytype)
{
	return m_keys[(UINT)keytype].keyState == KeyState::UP;
}

POINT InputManager::GetMousePos() const
{
	return m_mousePos;
}

