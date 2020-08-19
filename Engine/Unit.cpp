#include "stdafx.h"
#include "Unit.h"
#include "Animation.h"

Unit::Unit()
{
	// 0 = idle, 1 = walk, 2 = attack, 3 = die
	currentState = 0;

	// 0 = woodCutter, 1 = graveRobber, 2 = steamMan
	currentType = 0;

	//===========================================//

	woodCutterIdle = new Animation(5);
	woodCutterIdle->AddFrame("Resources/Char/Woodcutter/Woodcutter_idle/Woodcutter_idle_0_0.png");
	woodCutterIdle->AddFrame("Resources/Char/Woodcutter/Woodcutter_idle/Woodcutter_idle_0_1.png");
	woodCutterIdle->AddFrame("Resources/Char/Woodcutter/Woodcutter_idle/Woodcutter_idle_0_2.png");
	woodCutterIdle->AddFrame("Resources/Char/Woodcutter/Woodcutter_idle/Woodcutter_idle_0_3.png");
	AddChild(woodCutterIdle);

	//===========================================//

	woodCutterWalk = new Animation(5);
	woodCutterWalk->AddFrame("Resources/Char/Woodcutter/Woodcutter_Walk/Woodcutter_walk_0_0.png");
	woodCutterWalk->AddFrame("Resources/Char/Woodcutter/Woodcutter_Walk/Woodcutter_walk_0_1.png");
	woodCutterWalk->AddFrame("Resources/Char/Woodcutter/Woodcutter_Walk/Woodcutter_walk_0_2.png");
	woodCutterWalk->AddFrame("Resources/Char/Woodcutter/Woodcutter_Walk/Woodcutter_walk_0_3.png");
	woodCutterWalk->AddFrame("Resources/Char/Woodcutter/Woodcutter_Walk/Woodcutter_walk_0_4.png");
	woodCutterWalk->AddFrame("Resources/Char/Woodcutter/Woodcutter_Walk/Woodcutter_walk_0_5.png");
	AddChild(woodCutterWalk);

	//===========================================//

	woodCutterAttack = new Animation(5);
	woodCutterAttack->AddFrame("Resources/Char/Woodcutter/Woodcutter_attack1/Woodcutter_attack1_0_0.png");
	woodCutterAttack->AddFrame("Resources/Char/Woodcutter/Woodcutter_attack1/Woodcutter_attack1_0_1.png");
	woodCutterAttack->AddFrame("Resources/Char/Woodcutter/Woodcutter_attack1/Woodcutter_attack1_0_2.png");
	woodCutterAttack->AddFrame("Resources/Char/Woodcutter/Woodcutter_attack1/Woodcutter_attack1_0_3.png");
	woodCutterAttack->AddFrame("Resources/Char/Woodcutter/Woodcutter_attack1/Woodcutter_attack1_0_4.png");
	woodCutterAttack->AddFrame("Resources/Char/Woodcutter/Woodcutter_attack1/Woodcutter_attack1_0_5.png");
	AddChild(woodCutterAttack);

	//===========================================//
	
	graveRobberIdle = new Animation(5);
	graveRobberIdle->AddFrame("Resources/Char/Graverobber/Graverobber_idle/GraveRobber_idle_0_0.png");
	graveRobberIdle->AddFrame("Resources/Char/Graverobber/Graverobber_idle/GraveRobber_idle_0_1.png");
	graveRobberIdle->AddFrame("Resources/Char/Graverobber/Graverobber_idle/GraveRobber_idle_0_2.png");
	graveRobberIdle->AddFrame("Resources/Char/Graverobber/Graverobber_idle/GraveRobber_idle_0_3.png");
	AddChild(graveRobberIdle);

	//===========================================//

	graveRobberWalk = new Animation(5);
	graveRobberWalk->AddFrame("Resources/Char/Graverobber/Graverobber_walk/GraveRobber_walk_0_0.png");
	graveRobberWalk->AddFrame("Resources/Char/Graverobber/Graverobber_walk/GraveRobber_walk_0_1.png");
	graveRobberWalk->AddFrame("Resources/Char/Graverobber/Graverobber_walk/GraveRobber_walk_0_2.png");
	graveRobberWalk->AddFrame("Resources/Char/Graverobber/Graverobber_walk/GraveRobber_walk_0_3.png");
	graveRobberWalk->AddFrame("Resources/Char/Graverobber/Graverobber_walk/GraveRobber_walk_0_4.png");
	graveRobberWalk->AddFrame("Resources/Char/Graverobber/Graverobber_walk/GraveRobber_walk_0_5.png");
	AddChild(graveRobberWalk);

	//===========================================//

	graveRobberAttack = new Animation(5);
	graveRobberAttack->AddFrame("Resources/Char/Graverobber/Graverobber_attack/GraveRobber_attack1_0_0.png");
	graveRobberAttack->AddFrame("Resources/Char/Graverobber/Graverobber_attack/GraveRobber_attack1_0_1.png");
	graveRobberAttack->AddFrame("Resources/Char/Graverobber/Graverobber_attack/GraveRobber_attack1_0_2.png");
	graveRobberAttack->AddFrame("Resources/Char/Graverobber/Graverobber_attack/GraveRobber_attack1_0_3.png");
	graveRobberAttack->AddFrame("Resources/Char/Graverobber/Graverobber_attack/GraveRobber_attack1_0_4.png");
	graveRobberAttack->AddFrame("Resources/Char/Graverobber/Graverobber_attack/GraveRobber_attack1_0_5.png");
	AddChild(graveRobberAttack);

	//===========================================//

	steamManIdle = new Animation(5);
	steamManIdle->AddFrame("Resources/Char/Steamman/Steamman_idle/SteamMan_idle_0_0.png");
	steamManIdle->AddFrame("Resources/Char/Steamman/Steamman_idle/SteamMan_idle_0_1.png");
	steamManIdle->AddFrame("Resources/Char/Steamman/Steamman_idle/SteamMan_idle_0_2.png");
	steamManIdle->AddFrame("Resources/Char/Steamman/Steamman_idle/SteamMan_idle_0_3.png");
	AddChild(steamManIdle);

	//===========================================//

	steamManWalk = new Animation(5);
	steamManWalk->AddFrame("Resources/Char/Steamman/Steamman_walk/SteamMan_walk_0_0.png");
	steamManWalk->AddFrame("Resources/Char/Steamman/Steamman_walk/SteamMan_walk_0_1.png");
	steamManWalk->AddFrame("Resources/Char/Steamman/Steamman_walk/SteamMan_walk_0_2.png");
	steamManWalk->AddFrame("Resources/Char/Steamman/Steamman_walk/SteamMan_walk_0_3.png");
	steamManWalk->AddFrame("Resources/Char/Steamman/Steamman_walk/SteamMan_walk_0_4.png");
	steamManWalk->AddFrame("Resources/Char/Steamman/Steamman_walk/SteamMan_walk_0_5.png");
	AddChild(steamManWalk);

	//===========================================//

	steamManAttack = new Animation(5);
	steamManAttack->AddFrame("Resources/Char/Steamman/Steamman_attack/SteamMan_attack1_0_0.png");
	steamManAttack->AddFrame("Resources/Char/Steamman/Steamman_attack/SteamMan_attack1_0_1.png");
	steamManAttack->AddFrame("Resources/Char/Steamman/Steamman_attack/SteamMan_attack1_0_2.png");
	steamManAttack->AddFrame("Resources/Char/Steamman/Steamman_attack/SteamMan_attack1_0_3.png");
	steamManAttack->AddFrame("Resources/Char/Steamman/Steamman_attack/SteamMan_attack1_0_4.png");
	steamManAttack->AddFrame("Resources/Char/Steamman/Steamman_attack/SteamMan_attack1_0_5.png");
	AddChild(steamManAttack);
}

Unit::~Unit()
{
	SAFE_DELETE(woodCutterIdle);
	SAFE_DELETE(woodCutterWalk);
	SAFE_DELETE(woodCutterAttack);
	SAFE_DELETE(graveRobberIdle);
	SAFE_DELETE(graveRobberWalk);
	SAFE_DELETE(steamManAttack);
	SAFE_DELETE(steamManIdle);
	SAFE_DELETE(steamManWalk);
	SAFE_DELETE(steamManAttack);
}

void Unit::Update(float dTime)
{
	Object::Update(dTime);
}

void Unit::Render()
{
	Object::Render();

	switch (currentType)
	{
	case 0:
		switch (currentState)
		{
		case 0: woodCutterIdle->Render(); break;
		case 1: woodCutterWalk->Render(); break;
		case 2: woodCutterAttack->Render(); break;
		}
		break;

	case 1:
		switch (currentState)
		{
		case 0: graveRobberIdle->Render(); break;
		case 1: graveRobberWalk->Render(); break;
		case 2: graveRobberAttack->Render(); break;
		}
		break;

	case 2:
		switch (currentState)
		{
		case 0: steamManIdle->Render(); break;
		case 1: steamManWalk->Render(); break;
		case 2: steamManAttack->Render(); break;
		}
		break;
	}
}

int Unit::getCurrentState()
{
	return currentState;
}

int Unit::getCurrentType()
{
	return currentType;
}

void Unit::setCurrentState(int state)
{
	currentState = state;
}

void Unit::setCurrentType(int type)
{
	currentType = type;

	switch (type)
	{
	case 0: this->hp = 30; this->damage = 10; break;
	case 1: this->hp = 50; this->damage = 16; break;
	case 2: this->hp = 100; this->damage = 34; break;
	}
}