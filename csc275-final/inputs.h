#pragma once

// If the inputs were not imported
#ifndef __INPUTS_IMPORTED__
// Set that the inputs were imported
#define __INPUTS_IMPORTED__

// Include iostream
#include <iostream>

using namespace std;

// Define function to get input as integer
int getIntInput();

// Define function to force the user to press a key to continue
void forceToPressKeyToContinue();

#endif