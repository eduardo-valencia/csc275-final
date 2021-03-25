#include "entityTest.h";

void testEntityClass()
{
	const Classes classes = getClasses();
	Entity myEntity(1000, classes.swordsman, "TestEntity");
	myEntity.displayStats();
}