#include "ResourceManager.h"

ResourceManager::~ResourceManager()
{
	Clear();
}

void ResourceManager::Init(HWND hwnd, fs::path resourcePath)
{
	m_hwnd = hwnd;
	m_resourcePath = resourcePath;
}

void ResourceManager::Clear()
{

}