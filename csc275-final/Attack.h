#pragma once

// If the attack class was not imported
#ifndef __ATTACK_CLASS_IMPORTED__
// Define the attack class
#define __ATTACK_CLASS_IMPORTED__

#include <string>

using namespace std;

// Define Attack class to store attack's name and amount
class Attack
{
public:
	// Define default constructor
	Attack();

	// Define constructor type
	Attack(string newName, int amount);

	// Define getName method type
	string getName();

	// Define name mutator
	void setName(string newName);

	// Define getAmount method type
	int getAmount();

	// Define amount accessor
	void setAmount(int newAmount);

private:
	// Define name property
	string name;
	// Define amount property
	int amount;
};

#endif