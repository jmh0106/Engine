#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Unit.h"
#include "Number.h"
#include <vector>

class GameScene :
	public Scene
{
private:
	int playerGold;
	int towerUpgradeLevel;
	int towerUpgradeGold;
	float towerHp;
	int enemyMakeEnemyGold;

	std::vector<Unit*> unitList;
	std::vector<Sprite*> towerList;
	std::vector<Unit*> enemyUnitList;

	Number numArray[4];
	Number towerHpNumArray[4];
	Number towerUpgradeGoldNumArray[4];

public:
	GameScene();
	~GameScene();

	Sprite* gameSceneBackground;
	Sprite* makeWoodCutterButton;

	void Render();
	void Update(float dTime);

	void makeWoodCutter();
	void makeGraveRobber();
	void makeSteamMan();

	void enemyMakeWoodCutter();
	void enemyMakeGraveRobber();
	void enemyMakeSteamMan();

	void UpgradeTower();

	void enemyMakeEnemy();
};

