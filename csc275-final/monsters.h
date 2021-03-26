#pragma once

// If the file was not imported
#ifndef __MONSTERS_FILE_IMPORTED__
// Set that it was imported
#define __MONSTERS_FILE_IMPORTED__

// Include Monster header file
#include "Monster.h"
// Include Classes header file
#include "Classes.h"

// Define function to get a random attacker class
string getAttackerClass();

// Define function to generate a monster
Monster generateMonster(int round);

#endif