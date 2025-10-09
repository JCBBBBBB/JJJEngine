#pragma once
#include "pch.h"
#include "GameObject.h"

class Missile : public GameObject
{
public:
	Missile();
	virtual ~Missile() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
};

