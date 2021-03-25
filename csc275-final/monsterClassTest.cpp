#include  "monsterClassTest.h"

void testMonsterClass()
{
	struct Classes classes = getClasses();
	Monster monster(1, classes.archer, "Monster", 100);
	monster.attack(monster);
	monster.attack(monster);
}