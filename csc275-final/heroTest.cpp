#include "heroTest.h"

void testHeroClass()
{
	struct Classes classes = getClasses();
	Hero hero(25, classes.swordsman, "Gigglemesh", 100, "King of heroes.");
	hero.introduceSelf();
	cout << endl;
}