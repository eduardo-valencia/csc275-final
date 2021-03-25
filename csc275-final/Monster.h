#pragma once

// If the file was not importeed
#ifndef __MONSTER_CLASS_IMPORTED__
// Set that the file was imported
#define __MONSTER_CLASS_IMPORTED__

#include "Entity.h"
#include "attacks.h"
#include "Classes.h"
#include <stdlib.h>

// Define the Monster class, which extends the Entity class
class Monster : public Entity
{
public:
	// Use Entity constructor
	using Entity::Entity;

	// Override the attack method to choose random attack
	void attack(Entity enemy);

private:
	// Define method to get random attack
	Attack getRandomAttack();
};

#endif