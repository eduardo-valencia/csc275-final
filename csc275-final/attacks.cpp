// Include the header file
#include "attacks.h"

// Define method to get the vector of attacks
vector<Attack> getAttacks()
{
	// Define melee attack
	Attack melee("Melee", 50);
	// Define ranged attack
	Attack ranged("Ranged", 25);
	// Define magic attack
	Attack magic("Magic", 20);
	// Define attacks vector
	vector<Attack> attacks;
	// Add melee attack
	attacks.push_back(melee);
	// Add ranged attack
	attacks.push_back(ranged);
	// Add magic attack
	attacks.push_back(magic);
	// Return the attacks
	return attacks;
}