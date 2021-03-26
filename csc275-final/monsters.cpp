#include "monsters.h"

// Define method to get random attacker class
string getAttackerClass()
{
	// Get the classes
	struct Classes classes = getClasses();
	// Define the classes list
	const string classNameList[] = {
		classes.archer,
		classes.lancer,
		classes.shielder,
		classes.swordsman
	};
	// Choose a random class index
	const int classIndex = rand() % 3;
	// Return a random class
	return classNameList[classIndex];
}

// Define method to generate monster
Monster generateMonster(int round)
{
	// Define minimum enemy health
	const int baseHealth = 50;
	// Define health, with round modifier
	const int health = baseHealth * round;
	// Get attacker class
	const string attackerClass = getAttackerClass();
	// Define base attack amount
	const int baseAttack = 25;
	// Return a new monster
	return Monster(baseAttack, attackerClass, "Monster", health);
}