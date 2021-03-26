// csc275-final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "inputs.h"
#include "Hero.h"
#include "Monster.h"
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
    vector<Hero> heroes;
    struct Classes classes = getClasses();
    Hero hercules(100, classes.swordsman, "Hercules", 5000, "I am the god of strength");
    Hero gilgamesh(100, classes.archer, "Gilgamesh", 4000, "I am the strongest hero, the hero who defied the heavens.");
    Hero leonidas(100, classes.shielder, "Leonidas", 4000, "King of Sparta");
    Hero romulus(100, classes.lancer, "Romulus", 4500, "Founder of Rome");
    heroes.push_back(hercules);
    heroes.push_back(gilgamesh);
    heroes.push_back(leonidas);
    heroes.push_back(romulus);
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

// Define function to play all rounds
void playRounds(bool& continuePlaying)
{
    // Get chosen hero
    Hero hero = selectHero();
    // Define variable to store round index
    int roundNumber = 1;
    // While the hero is not dead and there are still rounds remaining
    while (hero.getHealth() && roundNumber <= 3)
    {
        // Define a new round
        Round round(roundNumber, hero);
        // Start round
        round.start();
        // Increment round number
        ++roundNumber;
    }
    // Update whether the user wants to continue playing
    askIfUserWantsToContinuePlaying(continuePlaying);
}

void askToContinue()
{
    cout << "Press any key to continue.\n";
    forceToPressKeyToContinue();
}

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
