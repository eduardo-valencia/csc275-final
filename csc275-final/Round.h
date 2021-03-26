#pragma once

#ifndef __ROUND_CLASS_DEFINED__
#define __ROUND_CLASS_DEFINED__

#include "monsters.h"
#include "Hero.h"
#include "inputs.h"
#include <iostream>
#include <vector>

class Round
{
public:
	Round(int roundNumber, Hero& hero);

	void start();

private:
	int roundNumber;

	Hero& hero;

	void displayAttackChoice(Attack attack, int attackIndex);

	Attack selectAttack();

	void addBoss(vector<Monster>& monsters);

	void addGeneratedMonsters(vector<Monster>& monsters);

	int getAttackChoice(vector<Attack>& attacks);

	vector<Monster> generateAllMonsters(int waveNumber);

	vector<Monster> getAliveMonsters(vector<Monster>& monsters);

	void exchangeAttacks(vector<Monster>& monsters);

	void startWave(int waveNumber);

	void displayAllStats(vector<Monster>& monsters);
};

#endif