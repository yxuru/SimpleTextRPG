
#include "Locations.h"
#include "PlayerOwnedStates.h"
#include <iostream>
#include "Enemy.h"
#include <thread>

void Town(GameState& currentState) {

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



void Forest(GameState& currentState) {


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



void Encounter(GameState& currentState) {

	int choice;
	int size = static_cast<int>(Enemies::EnemyFinal);
	Enemies currentEnemy = static_cast<Enemies>(rand() % size);

	std::cout << "A " << EnemyToString(currentEnemy) << " hath appeared!!" << "\n1.Attack \n2.Run away\n";     // RANDOM ENEMY INSERT HERE

	std::cin >> choice;

	if (choice != 1 && choice != 2) {
		std::cout << "Curse thee!";
		std::this_thread::sleep_for(std::chrono::seconds(3));
		currentState = GameState::Quit;
	}

	else if (choice == 1)
		currentState = GameState::Forest;

	else if (choice == 2)
		currentState = GameState::Forest;


}

