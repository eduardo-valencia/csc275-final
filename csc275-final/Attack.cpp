#include "Attack.h"

// Define attack's constructor
Attack::Attack() {
	// Initialize amount
	amount = 0;
}

// Define attack's constructor to set its properties
Attack::Attack(string newName, int newAmount) : name(newName), amount(newAmount)
{

}

// Define name accessor
string Attack::getName()
{
	return name;
}

// Define name mutator
void Attack::setName(string newName)
{
	name = newName;
}

// Define amount accessor
int Attack::getAmount()
{
	return amount;
}

// Define amount mutator
void Attack::setAmount(int newAmount)
{
	amount = newAmount;
}