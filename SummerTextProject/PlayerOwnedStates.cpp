
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

	

	if (choice == 1)
		currentState = GameState::Forest;

	else if (choice == 2) {
		std::cout << "Welcome to the inn. Would you like to shop [1] or rest [2]?\n";
		std::cin >> choice;
		if (choice == 1) {
			std::cout << "You currently have " << game.player.gold << " gold.\n";
		}
		else if (choice == 2) {
			std::cout << "Priest Marie: I'll get you fixed up!\nHealing...\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "Done! Be safe out there.\n";
			game.player.health == game.player.maxHealth;
		}
		else {
			std::cout << "Curse thee!";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			currentState = GameState::Quit;
		}
	}
	else if (choice == 3) {
		std::cout << "See you on our next adventure traveler!";
		std::this_thread::sleep_for(std::chrono::seconds(1));
		currentState = GameState::Quit;
		}

	else {
		std::cout << "Curse thee!";
		std::this_thread::sleep_for(std::chrono::seconds(3));
		currentState = GameState::Quit;
	}

}



void Forest(GameState& currentState, GameContext& game) {


	int choice;

	std::cout << "Forest of Uthgrot" << "\n1. Scout \n2. Return to Town\n";

	std::cin >> choice;

	if (choice != 1 && choice != 2) {
		std::cout << "Curse thee!";
		std::this_thread::sleep_for(std::chrono::seconds(2));
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
		std::this_thread::sleep_for(std::chrono::seconds(2));
		currentState = GameState::Quit;
	}

	else if (choice == 1) {
		std::cout << game.player.name << " swings at the enemy!\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
		currentEnemy.health -= game.player.attack;			// add a chance here
		std::cout << game.player.name << " damages the " << currentEnemy.name << " for " << game.player.attack << " health!\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
		if (currentEnemy.health < 0) {
			currentEnemy.health = 0;
			std::cout << "The " << currentEnemy.name << " has been defeated!\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			break;
		}
		std::cout << "The " << currentEnemy.name << " currently has " << currentEnemy.health << " health remaining.\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "The " << currentEnemy.name << " swings at " << game.player.name << "!\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
		game.player.health -= currentEnemy.attack;         // add a chance here
		if (game.player.health < 0) {
			game.player.health = 0;
			std::cout << game.player.name << " has been defeated! You must flee!\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			break;
		}
		std::cout << game.player.name << " has " << game.player.health << " health remaining!\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	else if (choice == 2)
		if (rand() % 3 == 0) {
			std::cout << "You failed to escape!\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "The " << currentEnemy.name << " swings at " << game.player.name << "!\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			game.player.health -= currentEnemy.attack;         // add a chance here
			if (game.player.health < 0) {
				game.player.health = 0;
				std::cout << game.player.name << " has been defeated! You must flee!\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				break;
			}
			std::cout << game.player.name << " has " << game.player.health << " health remaining!\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		else
			escaped = true;
		
	}

	if (!escaped) {
		std::cout << "You win! Here is your reward... " << currentEnemy.gold << " gold.\n";
		game.player.gold += currentEnemy.gold;
	}
	else
		std::cout << "You escaped! Better be careful out here...\n";
		
	std::this_thread::sleep_for(std::chrono::seconds(2));
	currentState = GameState::Forest;

}

