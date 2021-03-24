#include "attacks.h"
#include <iostream>

using namespace std;

void testAttacks()
{
	vector<Attack> attacks = getAttacks();
	for (int attackIndex = 0; attackIndex < attacks.size(); ++attackIndex)
	{
		Attack attack = attacks[attackIndex];
		cout << "Name: " << attack.getName();
		cout << endl;
		cout << "Amount: " << attack.getAmount();
		cout << endl;
	}
}