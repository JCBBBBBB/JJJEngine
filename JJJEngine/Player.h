#pragma once
#include "pch.h"


class Player : public GameObject
{
public:
	Player();
	virtual ~Player() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;


private:

};

