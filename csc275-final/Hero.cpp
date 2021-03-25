#include "Hero.h"

// Define hero constructor and use parent's constructor
Hero::Hero(int newBaseAttack, string newAttackerClass, string newName, int newHealth, string newDescription) : Entity(newBaseAttack, newAttackerClass, newName, newHealth)
{
	// Initialize description
	description = newDescription;
}

// Define description accessor
string Hero::getDescription()
{
	return description;
}

// Define method for hero to introduce themselves
void Hero::introduceSelf()
{
	cout << "Hi!\n";
	cout << "I am " << getName() << ".\n";
	cout << getDescription() << endl;
	cout << "It is an honor to fight by your side.\n";
}

// Define method to show enemy stats and attacker class
void Hero::showEnemyInfo(Monster monster)
{
	// Show monster's stats
	monster.displayStats();
	cout << "Attacker Class: " << monster.getAttackerClass() << endl;
	cout << endl;
}

// Define method to make hero show info about the monsters
void Hero::scanEnemies(vector<Monster> monsters)
{
	// For each monster
	for (int monsterIndex = 0; monsterIndex < monsters.size(); ++monsterIndex)
	{
		// Get monster
		Monster monster = monsters[monsterIndex];
		// Show info on monster
		showEnemyInfo(monster);
	}
}

// Define method for hero to alert player of enemies before each wave begins
void Hero::alertPlayerOfEnemies(vector<Monster> monsters, int waveNumber, int roundNumber)
{
	// Make hero announce wave
	talk("Here comes wave " + to_string(waveNumber) + "!");
	// If it is the last wave on the last round
	if (waveNumber == 3 && roundNumber == 3)
	{
		// Make the hero announce that the final boss is here
		talk("Here comes the final boss!");
	}
	// Show enemy info
	scanEnemies(monsters);
}