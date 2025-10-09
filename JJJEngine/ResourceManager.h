#pragma once
#include "pch.h"

class ResourceManager
{
	SINGLETONE(ResourceManager);

public:
	~ResourceManager();

	void Init(HWND hwnd, fs::path resourcePath);
	void Clear();

	const fs::path& GetResourcePath()
	{
		return m_resourcePath;
	}
private:
	HWND m_hwnd;
	fs::path m_resourcePath;
};

