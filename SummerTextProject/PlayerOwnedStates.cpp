
#include "Locations.h"
#include "PlayerOwnedStates.h"
#include <iostream>
#include "Enemy.h"
#include <thread>
#include "GameContext.h"

void Town(GameState& currentState, GameContext& game) {

	int choice;

	std::cout << "----Town of Luondle----" << "\nChoose your adventure..." << "\n1. Enter Forest \n2. Enter the Inn\n3. Quit\n";
	
	std::cin >> choice;

	if (choice != 1 && choice != 2) {
		std::cout << "Curse thee!";
		std::this_thread::sleep_for(std::chrono::seconds(3));
		currentState = GameState::Quit;
	}

	else if (choice == 1)
		currentState = GameState::Forest;

	else if (choice == 3)
		currentState = GameState::Quit;

	else {
		std::cout << "Welcome to the inn. Would you like to shop [1] or rest [2]?\n";
		std::cin >> choice;
		if (choice == 1) {
			std::cout << "You currently have " << game.player.gold << " gold.";
		}
		else if (choice == 2) {

		}
		else {
			std::cout << "Curse thee!";
			std::this_thread::sleep_for(std::chrono::seconds(3));
			currentState = GameState::Quit;
		}
	}

}



void Forest(GameState& currentState, GameContext& game) {


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



void Encounter(GameState& currentState, GameContext& game) {

	int choice;
	const std::vector<Enemy> enemies = game.assets.GetEnemies();

	size_t size = enemies.size(); // Get size of enemy list for ids
	Enemy currentEnemy = enemies.at(rand() % size); // create a copy of template

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

