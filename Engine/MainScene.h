#pragma once
#include "Scene.h"
#include "Sprite.h"

class MainScene :
	public Scene
{
public:
	MainScene();
	~MainScene();

	Sprite* backGround;
	Sprite* startButton;
	Sprite* exitButton;
	Sprite* title;

	void Render();
	void Update(float dTime);
};

