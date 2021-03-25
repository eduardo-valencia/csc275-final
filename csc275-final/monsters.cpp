#include "monsters.h"

// Define method to get random attacker class
string getAttackerClass()
{
	struct Classes classes = getClasses();
	const string classNameList[] = {
		classes.archer,
		classes.lancer,
		classes.shielder,
		classes.swordsman
	};
	const int classIndex = rand() % 3;
	return classNameList[classIndex];
}

// Define method to generate monster
Monster generateMonster(int round)
{
	// Define minimum enemy health
	const int baseHealth = 1000;
	// Define health, with round modifier
	const int health = baseHealth * round;
	// Get attacker class
	const string attackerClass = getAttackerClass();
	// Return a new monster
	return Monster(25, attackerClass, "Monster");
}