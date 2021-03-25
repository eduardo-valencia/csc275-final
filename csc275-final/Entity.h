#pragma once

// If the file was not importeed
#ifndef __ENTITY_FILE_IMPORTED__
// Set that the file was imported
#define __ENTITY_FILE_IMPORTED__

#include <string>
#include <iostream>
#include "Attack.h"

using namespace std;

// Define entity class with methods and properties for both players and enemies.
class Entity
{
public:
	// Define constructor
	Entity(int newBaseAttack, string newAttackerClass, string newName);

	// Define method to decrease health
	void decreaseHealth(int damage);

	// Define method to get if the current entity counters another enemy
	bool getIfCountersEnemy(Entity& enemy);

	// Define method to attack a target
	void attack(Attack& type, Entity& enemy);

	// Define health accessor
	int getHealth();

	// Define method to make entity talk
	void talk(string message);

	// Define method to display the entity's stats
	void displayStats();

	// Define attackerClass accessor
	string getAttackerClass();

	// Define name accessor
	string getName();

	// Define attack multiplier accessor
	float getAttackMultiplier();

	// Define defense multiplier accessor
	float getDefenseMultiplier();
private:
	// Define int to store the entity's base attack amount
	int baseAttack;

	// Define property to store attacker class
	string attackerClass;

	// Define property to store health
	int health;

	// Define property to store attack multiplier
	float attackMultiplier;

	// Define float to store defense multiplier
	float defenseMultiplier;

	// Define name property
	string name;

	// Define attackMultiplier mutator
	void setAttackMultiplier(float newAttackMultiplier);

	// Define defenseMultiplier mutator
	void setDefenseMultiplier(float newDefenseMultiplier);

	// Define method to get the base attack amount, the base attack affected by multipliers
	float getBaseAttackAmount(Attack& attackType);

	// Define method to get total attack amount
	float getAttackAmount(Attack& attackType, Entity& enemy);

	// Define method to set attack's multipliers
	void setEffects(Attack& attack);
};

#endif