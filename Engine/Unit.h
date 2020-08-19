#pragma once
#include "Object.h"
#include "Sprite.h"
#include "Animation.h"

class Unit : public Object
{
private:
	Animation* woodCutterIdle;
	Animation* woodCutterWalk;
	Animation* woodCutterAttack;

	Animation* graveRobberIdle;
	Animation* graveRobberWalk;
	Animation* graveRobberAttack;

	Animation* steamManIdle;
	Animation* steamManWalk;
	Animation* steamManAttack;

	int currentState;
	int currentType;

public:
	Unit();
	~Unit();

	void Update(float dTime);
	void Render();

	int getCurrentState();
	int getCurrentType();

	void setCurrentState(int state);
	void setCurrentType(int type);

	float hp;
	float damage;
};