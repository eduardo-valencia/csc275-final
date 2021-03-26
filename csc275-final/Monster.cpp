#include "Monster.h"

// Define method to get random attack
Attack Monster::getRandomAttack()
{
	// Get attacks
	vector<Attack> attacks = getAttacks();
	// Choose attack index
	const int attackIndex = rand() % (attacks.size() - 1);
	// Return an attack
	return attacks[attackIndex];
}

// Override the attack method to choose random attack
void Monster::attack(Entity& enemy)
{
	// Get random attack
	Attack attack = getRandomAttack();
	// Use Entity's attack method
	Entity::attack(attack, enemy);
}