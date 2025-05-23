#include "entityTest.h";

const Classes classes = getClasses();
vector<Attack> attacks = getAttacks();

Entity getShielder()
{
	Entity shielder(1, classes.shielder, "Mash Kyrielight", 100);
	return shielder;
}

Entity getSwordsman()
{
	Entity swordsman(1, classes.swordsman, "Saber", 100);
	return swordsman;
}

Entity getArcher()
{
	Entity archer(1, classes.archer, "Emiya Shirou", 100);
	return archer;
}

void testShieldersTakeHalfDamage()
{
	Entity shielder = getShielder();
	Entity swordsman = getSwordsman();
	const int shielderInitialHealth = shielder.getHealth();
	const int swordsmanInitialHealth = swordsman.getHealth();
	swordsman.attack(attacks[0], shielder);
	swordsman.attack(attacks[0], swordsman);
	const int shielderDamage = shielderInitialHealth - shielder.getHealth();
	const int swordsmanDamage = swordsmanInitialHealth - swordsman.getHealth();
	if (shielderDamage * 2 != swordsmanDamage)
	{
		throw "Shielder does not take half of damage.";
	}
	cout << endl;
}

void testCountersDealDoubleDamage()
{
	Entity archer = getArcher();
	Entity swordsman = getSwordsman();
	archer.attack(attacks[0], swordsman);
	archer.attack(attacks[0], archer);
}

void testRangedAttacksHaveDefenseMultipliers()
{
	Entity archer = getArcher();
	archer.attack(attacks[1], archer);
	archer.attack(attacks[1], archer);
}

void testMagicAttacksHaveAttackMultipliers()
{
	Entity archer = getArcher();
	archer.attack(attacks[2], archer);
	archer.attack(attacks[2], archer);
}

void testEntitiesCanTalk()
{
	Entity archer = getArcher();
	archer.talk("Hi! My name is Emiya.");
}

void testEntityClass()
{
	Entity myEntity(1000, classes.swordsman, "Hero", 100);
	myEntity.displayStats();
	cout << endl;

	Entity myEntity2(2, classes.lancer, "Mongrel", 100);
	myEntity2.decreaseHealth(1);
	myEntity2.displayStats();
	cout << endl;
	myEntity2.decreaseHealth(1000);
	myEntity2.displayStats();
	cout << endl;

	Entity lancer(1, classes.lancer, "Lancer", 100);
	Entity archer = getArcher();
	Entity swordsman = getSwordsman();
	Entity shielder = getShielder();

	if (!swordsman.getIfCountersEnemy(lancer))
	{
		throw "Swordsman does not counter lancer";
	}
	else if (!archer.getIfCountersEnemy(swordsman))
	{
		throw  "Archer does not counter swordsman.";
	}

	Entity enemy(500, classes.shielder, "Shielder", 100);
	cout << endl;
	enemy.attack(attacks[0], myEntity);
	myEntity.displayStats();
	cout << endl;

	testShieldersTakeHalfDamage();
	cout << endl;
	testCountersDealDoubleDamage();
	cout << endl;
	testRangedAttacksHaveDefenseMultipliers();
	cout << endl;
	testMagicAttacksHaveAttackMultipliers();
	cout << endl;
	testEntitiesCanTalk();
}