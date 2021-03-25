#pragma once

// If the hero class was not imported
#ifndef __HERO_CLASS_IMPORTED__
// Set that it was imported
#define __HERO_CLASS_IMPORTED__

#include "Entity.h"
#include "Monster.h"
#include <vector>

// Define the "Hero" class, extending from the Entity class
class Hero : public Entity
{
public:
	// Define constructor type
	Hero(int baseAttack, string attackerClass, string name, int health, string description);

	// Define method to get description
	string getDescription();

	// Define method to introduce self
	void introduceSelf();

	// Define method to display stats of enemies
	void scanEnemies(vector<Monster> monsters);

	// Define method to alert player of enemies at beginning of wave
	void alertPlayerOfEnemies(vector<Monster> monsters, int waveNumber, int roundNumber);

private:
	// Define variable to store description
	string description;

	// Define method for hero to alert player of enemies before each wave begins
	void showEnemyInfo(Monster monster);
};

#endif