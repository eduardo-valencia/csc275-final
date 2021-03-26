#include "testRound.h"

void testRoundClass()
{
	struct Classes classes = getClasses();
	Hero hero(100, classes.archer, "Gilgamesh", 5000, "King of Heroes");
	for (int roundNumber = 1; roundNumber <= 3; ++roundNumber)
	{
		Round round1(roundNumber, hero);
		round1.start();
	}
}