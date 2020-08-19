#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene()
{
	playerGold = 100;
	towerUpgradeGold = 0;
	towerHp = 1000;
	enemyMakeEnemyGold = 100;

	gameSceneBackground = new Sprite("Resources/Image/Game/background.png");
	gameSceneBackground->setPos(0, -200);
	towerUpgradeLevel = 0;

	Sprite* tempTower = new Sprite("Resources/Image/Tower/towerBottom.png");
	towerList.push_back(tempTower);

	tempTower = new Sprite("Resources/Image/Tower/towerTop.png");
	towerList.push_back(tempTower);

	UpgradeTower();

	for (int i = 0; i < 4; i++)
		numArray[i].setPos(0 + 60 * i, 10);

	for (int i = 0; i < 4; i++)
	{
		towerHpNumArray[i].setScale(0.4, 0.4);
		towerHpNumArray[i].setPos(65 + 24 * i, 630);
	}

	for (int i = 0; i < 4; i++)
	{
		towerUpgradeGoldNumArray[i].setScale(0.4, 0.4);
		towerUpgradeGoldNumArray[i].setPos(915 + 24 * i, 5);
	}
}

GameScene::~GameScene()
{
}

void GameScene::Render()
{
	gameSceneBackground->Render();

	for (auto& tower : towerList)
		tower->Render();
	
	for (auto& unit : unitList)
		unit->Render();

	for (auto& unit : enemyUnitList)
		unit->Render();

	for (int i = 0; i < 4; i++)
	{
		towerUpgradeGoldNumArray[i].Render();
		numArray[i].Render();
		towerHpNumArray[i].Render();
	}
}

void GameScene::Update(float dTime)
{
	numArray[0].setNum(playerGold / 1000);
	numArray[1].setNum(playerGold % 1000 / 100);
	numArray[2].setNum(playerGold % 100 / 10);
	numArray[3].setNum(playerGold % 10);

	towerUpgradeGoldNumArray[0].setNum(towerUpgradeGold / 1000);
	towerUpgradeGoldNumArray[1].setNum(towerUpgradeGold % 1000 / 100);
	towerUpgradeGoldNumArray[2].setNum(towerUpgradeGold % 100 / 10);
	towerUpgradeGoldNumArray[3].setNum(towerUpgradeGold % 10);

	towerHpNumArray[0].setNum((int)towerHp / 1000);
	towerHpNumArray[1].setNum((int)towerHp % 1000 / 100);
	towerHpNumArray[2].setNum((int)towerHp % 100 / 10);
	towerHpNumArray[3].setNum((int)towerHp % 10);

	if (inputManager->GetKeyState('A') == KEY_DOWN)
		makeWoodCutter();

	if (inputManager->GetKeyState('S') == KEY_DOWN)
		makeGraveRobber();

	if (inputManager->GetKeyState('D') == KEY_DOWN)
		makeSteamMan();

	if (inputManager->GetKeyState('F') == KEY_DOWN)
		UpgradeTower();

	if (inputManager->GetKeyState('G') == KEY_DOWN)
		enemyMakeEnemy();

	for (int i = 0; i < enemyUnitList.size(); i++)
	{
		enemyUnitList.at(i)->Update(dTime);

		if (i == 0)
		{
			if (enemyUnitList.at(0)->getPosX() < 200)
			{
				enemyUnitList.at(0)->setCurrentState(2);
				towerHp -= enemyUnitList.at(0)->damage * dTime;
			}
			else
			{
			enemyUnitList.at(0)->translate(-1, 0);
			enemyUnitList.at(0)->setCurrentState(1);
			}
		}
		else
		{
			if (enemyUnitList.at(i - 1)->getPosX() + 48 < enemyUnitList.at(i)->getPosX()) // 앞에 사람이 없음
			{
				enemyUnitList.at(i)->translate(-1, 0);
				enemyUnitList.at(i)->setCurrentState(1);
			}
			else // 앞에 사람이 있음
			{
				enemyUnitList.at(i)->setCurrentState(0);
			}
		}
	}

	for (int i = 0; i < unitList.size(); i++)
	{
		unitList.at(i)->Update(dTime);

		if ((i == 0) && (enemyUnitList.size() != 0))
		{
			if ((enemyUnitList.at(0)->getPosX() - 120 <= unitList.at(0)->getPosX()))
			{
				unitList.at(i)->setCurrentState(2);
				enemyUnitList.at(i)->setCurrentState(2);
				enemyUnitList.at(i)->translate(1, 0);

				unitList.at(i)->hp -= enemyUnitList.at(i)->damage * dTime;
				enemyUnitList.at(i)->hp -= unitList.at(i)->damage * dTime;
			}
			else
			{
				unitList.at(i)->translate(1, 0);
				unitList.at(i)->setCurrentState(1);
			}
		}
		else if (i == 0)
		{
			unitList.at(i)->translate(1, 0);
			unitList.at(i)->setCurrentState(1);
		}
		else // 맨 앞이 아님
		{
			if (unitList.at(i - 1)->getPosX() - 48 > unitList.at(i)->getPosX()) // 앞에 사람이 없음
			{
				unitList.at(i)->translate(1, 0);
				unitList.at(i)->setCurrentState(1);
			}
			else // 앞에 사람이 있음
			{
				unitList.at(i)->setCurrentState(0);
			}
		}
	}

	if (unitList.size() > 0)
	{
		if (unitList.at(0)->hp < 0)
		{
			Unit* tempUnit = unitList.at(0);
			unitList.erase(unitList.begin());
		}
	}

	if (enemyUnitList.size() > 0)
	{
		if (enemyUnitList.at(0)->hp < 0)
		{
			Unit* tempUnit = enemyUnitList.at(0);
			
			switch (tempUnit->getCurrentType())
			{
			case 0: playerGold += 50; break;
			case 1: playerGold += 80; break;
			case 2: playerGold += 150; break;
			}

			enemyUnitList.erase(enemyUnitList.begin());
		}
	}
}

void GameScene::makeWoodCutter()
{
	if (playerGold < 30) return;
	playerGold -= 30;

	Unit* tempUnit = new Unit;
	tempUnit->setCurrentType(0);
	tempUnit->setPos(70, 768 - 48 - 96);
	tempUnit->setScale(2, 2);

	unitList.push_back(tempUnit);
}

void GameScene::makeGraveRobber()
{
	if (playerGold < 50) return;
	playerGold -= 50;

	Unit* tempUnit = new Unit;
	tempUnit->setCurrentType(1);
	tempUnit->setPos(70, 768 - 48 - 96);
	tempUnit->setScale(2, 2);

	unitList.push_back(tempUnit);
}

void GameScene::makeSteamMan()
{
	if (playerGold < 100) return;
	playerGold -= 100;

	Unit* tempUnit = new Unit;
	tempUnit->setCurrentType(2);
	tempUnit->setPos(70, 768 - 48 - 96);
	tempUnit->setScale(2, 2);

	unitList.push_back(tempUnit);
}

void GameScene::enemyMakeWoodCutter()
{
	Unit* tempUnit = new Unit;
	tempUnit->setCurrentType(0);
	tempUnit->setPos(1100, 768 - 48 - 96);
	tempUnit->setScale(-2, 2);

	enemyUnitList.push_back(tempUnit);
}

void GameScene::enemyMakeGraveRobber()
{
	Unit* tempUnit = new Unit;
	tempUnit->setCurrentType(1);
	tempUnit->setPos(1100, 768 - 48 - 96);
	tempUnit->setScale(-2, 2);

	enemyUnitList.push_back(tempUnit);
}

void GameScene::enemyMakeSteamMan()
{
	Unit* tempUnit = new Unit;
	tempUnit->setCurrentType(2);
	tempUnit->setPos(1100, 768 - 48 - 96);
	tempUnit->setScale(-2, 2);

	enemyUnitList.push_back(tempUnit);
}

void GameScene::UpgradeTower()
{
	if (towerUpgradeLevel == 4) return;
	if (towerUpgradeGold > playerGold) return;

	towerHp += 500;
	playerGold -= towerUpgradeGold;
	towerUpgradeLevel++;
	towerUpgradeGold += 500;

	Sprite* tempTower = new Sprite("Resources/Image/Tower/towerMiddle.png");
	towerList.insert(towerList.begin() + 1, tempTower);

	for (auto& tower : towerList)
		tower->setScale(2, 2);

	for (int i = 0; i < towerList.size(); i++)
	{
		if (i == 0)
			towerList.at(0)->setPos(10, 590);
		else if (i != 1 + towerUpgradeLevel)
			towerList.at(i)->setPos(10, 590 - 132 * i);
		else
			towerList.at(1 + towerUpgradeLevel)->setPos(10, 590 - 132 * (i - 1) - 36);
	}
}

void GameScene::enemyMakeEnemy()
{
	int money;
	int random;

	money = enemyMakeEnemyGold;
	srand(GetTickCount());

	std::cout << money << ")" << std::endl;

	while (money > 30)
	{
		random = (int)rand() % 3;

		switch (random)
		{
		case 0: enemyMakeWoodCutter(); money -= 30; std::cout << "나무꾼 소환" << std::endl; break;
		case 1: enemyMakeGraveRobber(); money -= 50; std::cout << "도굴꾼 소환" << std::endl; break;
		case 2: enemyMakeSteamMan(); money -= 100; std::cout << "스팀맨 소환" << std::endl; break;
		}
	}

	enemyMakeEnemyGold += 100;
}
