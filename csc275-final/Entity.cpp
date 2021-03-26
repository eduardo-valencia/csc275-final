#include "Entity.h"
#include "Classes.h"

Entity::Entity(int newBaseAttack, string newAttackerClass, string newName, int newHealth)
{
	// Initialize health
	Entity::health = newHealth;
	// Initialize base attack
	Entity::baseAttack = newBaseAttack;
	// Initialize attacker class
	Entity::attackerClass = newAttackerClass;
	// Initialize name
	Entity::name = newName;
	// Initialize damage multiplier
	Entity::attackMultiplier = 1;
	// Initialize defense multiplier
	Entity::defenseMultiplier = 1;
};

void Entity::decreaseHealth(int damage)
{
	// If the damage is greater than health
	if (damage > health)
	{
		// Set health to zero
		health = 0;
	}
	// Otherwise
	else
	{
		// Subtract damage from health
		health = health - damage;
	}
}

// Define method to get if the current entity counters the enemy
bool Entity::getIfCountersEnemy(Entity& enemy)
{
	// Get classes
	const Classes classes = getClasses();
	// Return whether it is an archer and the enemy is a swordsman, or it is a swordsman and the enemy is a lancer
	return (attackerClass == classes.archer && enemy.getAttackerClass() == classes.swordsman) || (attackerClass == classes.swordsman && enemy.getAttackerClass() == classes.lancer);
}

// Define attackMultiplier accessor
void Entity::setAttackMultiplier(float newAttackMultiplier)
{
	// Set attack multiplier
	attackMultiplier = newAttackMultiplier;
}

// Define defenseMultiplier accessor
void Entity::setDefenseMultiplier(float newDefenseMultiplier)
{
	// Set defense multiplieer
	defenseMultiplier = newDefenseMultiplier;
}

// Define base attack's accessor
int Entity::getBaseAttack()
{
	// Return base attack
	return baseAttack;
}

// Define method to get the base attack with multipliers
float Entity::getDamageWithModifiers(Attack& attackType)
{
	// Return the base attack, modified by the attack type and multipliers
	return getBaseAttack() + attackType.getAmount() * getAttackMultiplier() * getDefenseMultiplier();
}

// Define method to get attack amount
float Entity::getAttackAmount(Attack& attackType, Entity& enemy)
{
	// Get classes
	const Classes classes = getClasses();
	// Get base attack amount
	const int baseAttack = getDamageWithModifiers(attackType);
	// Get  if the current entity counters the enemy
	const bool countersEnemy = getIfCountersEnemy(enemy);
	//  If it does counter the enemy
	if (countersEnemy)
	{
		// Double the damage
		return baseAttack * 2;
	}
	// Otherwise if the enemy is a shielder
	else if (enemy.getAttackerClass() == classes.shielder)
	{
		// Return half of the damage
		return baseAttack / 2;
	}
	// Otherwise, return the base attack
	return baseAttack;
}

// Define methods to set multipliers based on previous attack
void Entity::setEffects(Attack& attack)
{
	// Get attack type
	const string attackType = attack.getName();
	// If the attack type was ranged
	// Reset attack multiplier
	setAttackMultiplier(1);
	// Reset defense multiplier
	setDefenseMultiplier(1);
	if (attackType == "Ranged")
	{
		// Set the defense multiplier to 0.5 to take half damage
		setDefenseMultiplier(0.5);
	}
	// Otherwise if the attack type was "Magic"
	else if (attackType == "Magic")
	{
		// Set the attack multiplier to 2 to double attack amount
		setAttackMultiplier(2);
	}
}

void Entity::attack(Attack& type, Entity& enemy)
{
	// get attack amount
	const int amount = getAttackAmount(type, enemy);
	cout << getName() << " attacked and inflicted " << amount << " damage!\n";
	// Reduce enemy's health
	enemy.decreaseHealth(amount);
	// Set attack's effects
	setEffects(type);
}

// Define name accessor
string Entity::getName()
{
	// Return the name
	return name;
}

// Define health accessor
int Entity::getHealth()
{
	// Return the health
	return health;
}

// Define method to make entity talk
void Entity::talk(string message)
{
	//  Get name
	const string name = getName();
	cout << name << ": " << message << endl;
}

// Define method to get class type
string Entity::getAttackerClass()
{
	// Return the attacker class
	return attackerClass;
}

// Define attack multiplier's accessor
float Entity::getAttackMultiplier()
{
	// Return attack multiplier
	return attackMultiplier;
}

// Define defense multiplier's accessor
float Entity::getDefenseMultiplier()
{
	// Return defense multiplier
	return defenseMultiplier;
}

//  Define method to show entity stats
void Entity::displayStats()
{
	cout << getName() << " (" << getAttackerClass() << "):" << endl;
	cout << "Health: " << getHealth() << endl;
	cout << "Attack: " << getBaseAttack() << endl;
	cout << "Damage Multiplier: " << getAttackMultiplier() << endl;
	cout << "Defense Multiplier: " << getDefenseMultiplier() << endl;
}