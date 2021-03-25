#include "heroTest.h"

void testHeroClass()
{
	struct Classes classes = getClasses();
	Hero hero(25, classes.swordsman, "Gigglemesh", 100, "King of heroes.");
	hero.introduceSelf();
	cout << endl;


	for (int roundNumber = 1; roundNumber <= 3; ++roundNumber)
	{
		for (int waveNumber = 1; waveNumber <= 3; ++waveNumber)
		{
			vector<Monster> monsters;
			for (int monsterIndex = 0; monsterIndex < 3; ++monsterIndex)
			{
				monsters.push_back(generateMonster(roundNumber));
			}
			hero.alertPlayerOfEnemies(monsters, waveNumber, roundNumber);
			cout << endl;
		}
	}
}