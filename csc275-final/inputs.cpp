#include "inputs.h"

// Define function to get input as int
int getIntInput()
{
	// Define variable to store answe
	int answer;
	// Set answer
	cin >> answer;
	// While the input is not good
	while (!cin.good())
	{
		// Clear input
		cin.clear();
		cout << "Please enter the number as an integer.\n";
		// Update answer
		cin >> answer;
	}
	cout << endl;
	return answer;
}

void forceToPressKeyToContinue()
{
	// Define variable to store answer
	string answer;
	// Set answer
	cin >> answer;
	cout << endl;
}