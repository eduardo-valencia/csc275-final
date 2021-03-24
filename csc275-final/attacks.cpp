#include "attacks.h"

vector<Attack> getAttacks()
{
	Attack melee("Melee", 50);
	Attack ranged("Ranged", 25);
	Attack magic("Magic", 20);
	vector<Attack> attacks;
	attacks.push_back(melee);
	attacks.push_back(ranged);
	attacks.push_back(magic);
	return attacks;
}