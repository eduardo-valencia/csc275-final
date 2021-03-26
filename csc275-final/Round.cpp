#include "Round.h"

// Define round constructor
Round::Round(int newRoundNumber, Hero& newHero) : hero(newHero), roundNumber(newRoundNumber)
{
}

// Define method to show an attack choice, with the choice number
void Round::displayAttackChoice(Attack attack, int attackIndex)
{
	cout << attackIndex << ") " << attack.getName() << endl;
}

int Round::getAttackChoice(vector<Attack>& attacks)
{
	cout << "Please enter your attack choice:\n";
	// Get choice index
	int choiceIndex = getIntInput();
	// While the index isn't in range
	while (choiceIndex >= attacks.size() || choiceIndex < 0)
	{
		cout << "Please enter your choice as a valid number.\n";
		// Update input
		choiceIndex = getIntInput();
	}
	return choiceIndex;
}

// Define method to allow player to select an attack
Attack Round::selectAttack()
{
	// get the attacks list
	vector<Attack> attacks = getAttacks();
	// For each attack
	for (int attackIndex = 0; attackIndex < attacks.size(); ++attackIndex)
	{
		// Get attack
		Attack attack = attacks[attackIndex];
		// Display attack option
		displayAttackChoice(attack, attackIndex);
	}
	// Get the attack choice index
	const int attackChoice = getAttackChoice(attacks);
	// Return the chosen attack
	return attacks[attackChoice];
}

// Define method to add boss to monsters vector
void Round::addBoss(vector<Monster>& monsters)
{
	// Get random attacker class
	string attackerClass = getAttackerClass();
	// Create monster
	const Monster boss = Monster(200, attackerClass, "Goliath", 1000);
	// Add monster
	monsters.push_back(boss);
}

// Define method to add generated monsters
void Round::addGeneratedMonsters(vector<Monster>& monsters)
{
	// For up to three monsters
	for (int monsterIndex = 0; monsterIndex < 3; ++monsterIndex)
	{
		// Generate a monster
		Monster monster = generateMonster(roundNumber);
		// Add monster
		monsters.push_back(monster);
	}
}

// Define method to generate monsters for a wave, including the boss
vector<Monster> Round::generateAllMonsters(int waveNumber)
{
	// Define vector to store monsters
	vector<Monster> monsters;
	// If it is the final wave and round
	if (waveNumber == 3 && roundNumber == 3)
	{
		// Add boss
		addBoss(monsters);
	}
	// Otherwise
	else
	{
		// Add the generated monsters
		addGeneratedMonsters(monsters);
	}
	return monsters;
}

// Define method to get alive monsters
vector<Monster> Round::getAliveMonsters(vector<Monster>& monsters)
{
	// Define vector to store alive monsters
	vector<Monster> aliveMonsters;
	// For each monster
	for (int monsterIndex = 0; monsterIndex < monsters.size(); ++monsterIndex)
	{
		// Get the monster
		Monster monster = monsters[monsterIndex];
		// If the monster is still alive
		if (monster.getHealth() > 0)
		{
			// Add the monster
			aliveMonsters.push_back(monster);
		}
	}
	return aliveMonsters;
}

// Define method to allow players and monsters to attack each other
void Round::exchangeAttacks(vector<Monster>& monsters)
{
	// Get the player's chosen attack
	Attack attack = selectAttack();
	// Define variable to set monster to attack
	Monster& target = monsters[0];
	// Attack monster
	hero.attack(attack, target);
	// For each monster
	for (int monsterIndex = 0; monsterIndex < monsters.size(); ++monsterIndex)
	{
		// Set monster
		Monster& monster = monsters[monsterIndex];
		// If the monster is still alive
		if (monster.getHealth() > 0)
		{
			// Attack the player
			monster.attack(hero);
		}
	}
	cout << endl;
}

// Define method to display all entities' stats
void Round::displayAllStats(vector<Monster>& monsters)
{
	hero.displayStats();
	cout << endl;
	// Show enemy info
	hero.scanEnemies(monsters);
}

// Define method to start the wave
void Round::startWave(int waveNumber)
{
	// Generate the monsters
	vector<Monster> monsters = generateAllMonsters(waveNumber);
	// Have the hero alert player of the incoming enemies
	hero.alertPlayerOfEnemies(monsters, waveNumber, roundNumber);
	// While there are monsters and the hero is not dead
	while (monsters.size() && hero.getHealth())
	{
		// Exchange attacks between monsters and enemies
		exchangeAttacks(monsters);
		// Update the alive monsters
		monsters = getAliveMonsters(monsters);
		displayAllStats(monsters);
	}
}

// Define method to start
void Round::start()
{
	// Define int to store wave number
	int waveNumber = 1;
	cout << "Round " << roundNumber << " is starting!\n";
	cout << "Please press any key to continue.\n";
	// Force user to press key to continue
	forceToPressKeyToContinue();
	// While the hero is not dead and the wave number is less than three
	while (hero.getHealth() && waveNumber <= 3)
	{
		// Start the wave
		startWave(waveNumber);
		// Increment wave number
		++waveNumber;
	}
}