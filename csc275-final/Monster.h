#pragma once

// If the file was not importeed
#ifndef __MONSTER_CLASS_IMPORTED__
// Set that the file was imported
#define __MONSTER_CLASS_IMPORTED__

// Include the Entity header file
#include "Entity.h"
// Include the attacks header file
#include "attacks.h"
// Include Classes header file
#include "Classes.h"
// Include stdlib
#include <stdlib.h>

// Define the Monster class, which extends the Entity class
class Monster : public Entity
{
public:
	// Use Entity constructor
	using Entity::Entity;

	// Override the attack method to choose random attack
	void attack(Entity& enemy);

private:
	// Define method to get random attack
	Attack getRandomAttack();
};

#endif