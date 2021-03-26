#pragma once

// If the round class was not defined
#ifndef __ROUND_CLASS_DEFINED__
// Set that the round class was defined
#define __ROUND_CLASS_DEFINED__

#include "monsters.h"
#include "Hero.h"
#include "inputs.h"
#include <iostream>
#include <vector>

// Define the Round class
class Round
{
public:
	// Define Round's constructor with roundNumber and hero
	Round(int roundNumber, Hero& hero);

	// Define method to start round
	void start();

private:
	// Define round number to track current round
	int roundNumber;

	// Define hero property to store hero
	Hero& hero;

	// Define method to display an attack choice
	void displayAttackChoice(Attack attack, int attackIndex);

	// Define method to prompt user to select attack
	Attack selectAttack();

	// Define method to add boss to list of monsters
	void addBoss(vector<Monster>& monsters);

	// Define method to add normal monsters to list of monsters
	void addGeneratedMonsters(vector<Monster>& monsters);

	// Define method to prompt the user for their attack choice
	int promptForAttackChoice(vector<Attack>& attacks);

	// Define method to try getting a valid attack choice and provide exception handling
	int tryGettingAttackChoice(vector<Attack>& attacks);

	// Define method to get user's attack choice as an index.
	int getAttackChoice(vector<Attack>& attacks);

	// Define method to get vector of generated monsters
	vector<Monster> generateAllMonsters(int waveNumber);

	// Define method to get only alive monsters
	vector<Monster> getAliveMonsters(vector<Monster>& monsters);

	// Define method to make monsters and hero exchange attacks
	void exchangeAttacks(vector<Monster>& monsters);

	// Define method to start each wave
	void startWave(int waveNumber);

	// Define method to display stats of both hero and monsters
	void displayAllStats(vector<Monster>& monsters);
};

#endif