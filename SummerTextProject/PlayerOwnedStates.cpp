
#include "Locations.h"
#include "PlayerOwnedStates.h"
#include <iostream>
#include "Enemy.h"
#include <thread>
#include "DataManager.h"

void Town(GameState& currentState, DataManager& dataManager) {

	int choice;

	std::cout << "----Town of Luondle----" << "\nChoose your adventure..." << "\n1. Enter Forest \n2. Quit\n";
	
	std::cin >> choice;

	if (choice != 1 && choice != 2) {
		std::cout << "Curse thee!";
		std::this_thread::sleep_for(std::chrono::seconds(3));
		currentState = GameState::Quit;
	}

	else if (choice == 1)
		currentState = GameState::Forest;

	else if (choice == 2)
		currentState = GameState::Quit;

}



void Forest(GameState& currentState, DataManager& dataManager) {


	int choice;

	std::cout << "Forest of Uthgrot" << "\n1. Scout \n2. Return to Town\n";

	std::cin >> choice;

	if (choice != 1 && choice != 2) {
		std::cout << "Curse thee!";
		std::this_thread::sleep_for(std::chrono::seconds(3));
		currentState = GameState::Quit;
	}

	else if (choice == 1)
		currentState = GameState::Encounter;

	else if (choice == 2)
		currentState = GameState::Town;

}



void Encounter(GameState& currentState, DataManager& dataManager) {

	int choice;
	const std::vector<Enemy> enemies = dataManager.GetEnemies();

	size_t size = enemies.size(); // Get size of enemy list for ids
	Enemy selectedEnemy = enemies[rand() % size]; // grab a random enemy id
	Enemy currentEnemy = selectedEnemy; // create a copy of template

	std::cout << "A " << currentEnemy.name << " hath appeared!!\n";     // RANDOM ENEMY INSERT HERE
	bool escaped{ false };

	while (currentEnemy.health > 0 && !escaped) 
	{
	
	std::cout << "1.Attack \n2.Run Away\n";

	std::cin >> choice;

	if (choice != 1 && choice != 2) {
		std::cout << "Curse thee!";
		std::this_thread::sleep_for(std::chrono::seconds(3));
		currentState = GameState::Quit;
	}

	else if (choice == 1) {
		currentEnemy.health -= 2;
		std::cout << "The " << currentEnemy.name << " currently has " << currentEnemy.health << " health remaining.\n";
	}

	else if (choice == 2)
		if (rand() % 3 == 0) {
			std::cout << "You failed to escape!\n";
			std::cout << "The " << currentEnemy.name << " currently has " << currentEnemy.health << " health remaining.\n";
		}
		else
			escaped = true;
		
	}

	if (!escaped) {
		std::cout << "You win! Here is your reward... " << currentEnemy.gold << " gold.\n";
	}
	else
		std::cout << "You escaped! Better be careful out here...\n";
		
	std::this_thread::sleep_for(std::chrono::seconds(3));
	currentState = GameState::Forest;

}

