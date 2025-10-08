#include "InputManager.h"

int ASCII[(UINT)KeyType::END] =
{
	'Q','W','E','R','T','Y','U','I','O','P',
	'A','S','D','F','G','H','J','K','L',
	'Z','X','C','V','B','N','M',
	VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
};

void InputManager::Init()
{
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

			if (GetAsyncKeyState(ASCII[(UINT)key.keyType]) & 0x8000) // 어떤 키가 눌렸을 때
			{
				if (key.isPressed) // 전에 눌려 있으면
				{
					key.keyState = KeyState::PRESSED;
				}
				else // 전에 눌려 있지않고 지금 눌렸으면
				{
					key.keyState = KeyState::DOWN;
				}

				key.isPressed = true;
			}
			else // 어떤 키가 안눌렸을 때
			{
				if (key.isPressed) // 전에 눌려 있으면
				{
					key.keyState = KeyState::DOWN;
				}
				else // 전에 안 눌려 있으면
				{
					key.keyState = KeyState::NONE;
				}

				key.isPressed = false;
			}
	});
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