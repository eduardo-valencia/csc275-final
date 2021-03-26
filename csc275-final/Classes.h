#pragma once

// If the file was not importeed
#ifndef __CLASSES_FILE_IMPORTED__
// Set that the file was imported
#define __CLASSES_FILE_IMPORTED__

// Include string
#include <string>

using namespace std;

// Define struct with list of classes
struct Classes
{
	string shielder;
	string lancer;
	string archer;
	string swordsman;
};

// Define function to get a struct instance
struct Classes getClasses();

#endif