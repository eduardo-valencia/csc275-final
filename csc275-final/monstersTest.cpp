#include "monstersTest.h"

void testMonsters()
{
	for (int round = 1; round <= 3; ++round)
	{
		Monster monster = generateMonster(1);
		monster.displayStats();
		cout << "Attacker class: " << monster.getAttackerClass() << endl;
		cout << endl;
	}
}