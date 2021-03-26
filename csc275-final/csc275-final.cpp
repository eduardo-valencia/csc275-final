// csc275-final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Include iostream
#include <iostream>
// include time
#include <time.h>
// include stdlib
#include <stdlib.h>
// Include vector
#include <vector>
// Include thread
#include <thread>
// Include file with input utilities
#include "inputs.h"
// Include Hero class
#include "Hero.h"
// Include Monster class
#include "Monster.h"
// include Round
#include "Round.h"

using namespace std;

// Define func to seed random number generator
void seedRandomNumberGenerator()
{
    // Seed random number generator with time
    srand(time(0));
}

// Define func to welcome user
void welcome()
{
    cout << "Welcome!\n";
    cout << "You are a hero fighting for the kingdom of Lagunica.\n";
    cout << "We are facing an invasion, and groups of monsters have viciously attacked us throughout the kingdom.\n";
    cout << "We must stop them before they can attack us again.\n";
    cout << "Yesterday, a scout located one of their bases south of the mountains.\n";
    cout << "The king has asked you to take down the enemy's army by commanding your hero.\n";
    cout << "Will you help us?\n";
    cout << endl;
}

// Define function to show hero choice
void displayHero(Hero& hero, int index)
{
    cout << index << ") " << hero.getName() << endl;
}

// Define function to display the hero choices
void displayHeroes(vector<Hero>& heroes)
{
    // For each hero
    for (int heroIndex = 0; heroIndex < heroes.size(); ++heroIndex)
    {
        // Get the hero
        Hero& hero = heroes[heroIndex];
        // Show hero choice
        displayHero(hero, heroIndex);
    }
}

// Define function to get hero choice
int getHeroChoice(vector<Hero>& heroes)
{
    cout << "Please enter your hero choice:\n";
    // Get choice index
    int choiceIndex = getIntInput();
    // While the index isn't in range
    while (choiceIndex >= heroes.size() || choiceIndex < 0)
    {
        cout << "Please enter your choice as a valid number.\n";
        // Update input
        choiceIndex = getIntInput();
    }
    return choiceIndex;
}

// Define function to get heroes
vector<Hero> getHeroes()
{
    // Define vector to store heroes
    vector<Hero> heroes;
    // Get the classes
    struct Classes classes = getClasses();
    // Create hercules
    Hero hercules(100, classes.swordsman, "Hercules", 5000, "I am the god of strength");
    // create gilgamesh
    Hero gilgamesh(100, classes.archer, "Gilgamesh", 4000, "I am the strongest hero, the hero who defied the heavens.");
    // Create leonidas
    Hero leonidas(100, classes.shielder, "Leonidas", 4000, "King of Sparta");
    // Create romulus
    Hero romulus(100, classes.lancer, "Romulus", 4500, "Founder of Rome");
    // add hercules
    heroes.push_back(hercules);
    // Add gilgamesh
    heroes.push_back(gilgamesh);
    // Add leonidas
    heroes.push_back(leonidas);
    // Add romulus
    heroes.push_back(romulus);
    // Return heroes
    return heroes;
}

// Define function to select hero
Hero selectHero()
{
    // Get heroes list
    vector<Hero> heroes = getHeroes();
    // Show hero choices
    displayHeroes(heroes);
    // Get hero choice
    int heroChoice = getHeroChoice(heroes);
    // Return chosen hero
    return heroes[heroChoice];
}

// Define function to update whether the user wants to continue playing
void askIfUserWantsToContinuePlaying(bool& continuePlaying)
{
    // Define variable to store user's answer
    string answer;
    cout << "Do you want to continue playing? (yes / no)\n";
    // Set answer from user input
    cin >> answer;
    // While the answer is neither yes nor no
    while (answer != "yes" && answer != "no")
    {
        cout << "Please input your answer as yes or no.\n";
        // Update the answer
        cin >> answer;
    }
    // Set the continue playing variable
    continuePlaying = answer == "yes";
}

// Define function to show win / loss status
void displayResults(Hero& hero)
{
    // If the hero is alive
    if (hero.getHealth())
    {
        cout << "Congrats! You won!\n";
    }
    // Otherwise, explain they lost
    else
    {
        cout << "Sorry, your hero died.\n";
    }
}

// Define function to create a new round
void createRound(int& roundNumber, Hero& hero)
{
    // Define a new round
    Round round(roundNumber, hero);
    // Start round
    round.start();
    // Increment round number
    ++roundNumber;
}

// Define function to create a new thread for creating a round
void createRoundThread(int& roundNumber, Hero& hero)
{
    // Define variable for thread
    thread roundThread(createRound, ref(roundNumber), ref(hero));
    // Wait for the thread
    roundThread.join();
}

// Define function to play all rounds
void playRounds(bool& continuePlaying)
{
    // Get chosen hero
    Hero hero = selectHero();
    // Have the hero introduce themselves
    hero.introduceSelf();
    cout << endl;
    // Define variable to store round index
    int roundNumber = 1;
    // While the hero is not dead and there are still rounds remaining
    while (hero.getHealth() && roundNumber <= 3)
    {
        // Create a new thread for the round
        createRoundThread(roundNumber, hero);
    }
    // Display win / loss status
    displayResults(hero);
    // Update whether the user wants to continue playing
    askIfUserWantsToContinuePlaying(continuePlaying);
}

// Define function to ask the user to continue and force them to press key
void askToContinue()
{
    cout << "Press any key to continue.\n";
    // Force them to press key to continue
    forceToPressKeyToContinue();
}

// Define main function
int main()
{
    // Welcome user
    welcome();
    // Ask the user to press key to continue
    askToContinue();
    // Seed random number generator
    seedRandomNumberGenerator();
    // Define boolean to store whether to continue playing
    bool continuePlaying = true;
    // While the user wants to continue playing
    while (continuePlaying)
    {
        // Play the game
        playRounds(continuePlaying);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
