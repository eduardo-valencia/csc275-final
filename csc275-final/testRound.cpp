#include "testRound.h"

void testRoundClass()
{
	struct Classes classes = getClasses();
	Hero hero(100, classes.swordsman, "Gigglemesh", 1000, "King of Heroes");
	Round round1(1, hero);
	round1.start();
}