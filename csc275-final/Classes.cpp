// Include the header file
#include "Classes.h"

// Define function to get struct with class names
struct Classes getClasses()
{
	// Define Classes struct with class names.
	struct Classes classes = { "Shielder", "Lancer", "Archer", "Swordsman" };
	// Return the classes
	return classes;
}
