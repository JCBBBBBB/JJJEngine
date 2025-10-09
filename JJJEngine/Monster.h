#pragma once
#include "pch.h"
#include "GameObject.h"

class Monster : public GameObject
{
public:
	Monster();
	virtual ~Monster() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:

};

