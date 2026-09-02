
#include "Locations.h"
#include "PlayerOwnedStates.h"
#include <iostream>
#include "Enemy.h"
#include <thread>
#include "GameContext.h"
#include "Combat.h"
#include "EnemyAI.h"

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



void Encounter(GameState& currentState, GameContext& game)
{
    const std::vector<Enemy>& enemies = game.assets.GetEnemies();

    if (enemies.empty())
    {
        std::cout << "There are no enemies to encounter!\n";
        currentState = GameState::Forest;
        return;
    }

    size_t size = enemies.size();

    // Copy the enemy template so its health can change during combat.
    Enemy currentEnemy = enemies.at(rand() % size);

    std::cout << "A " << currentEnemy.name
        << " hath appeared!!\n";

    EnemyAI enemyAI;

    bool playerEscaped = false;
    bool enemyEscaped = false;

    while (game.player.health > 0 &&
        currentEnemy.health > 0 &&
        !playerEscaped &&
        !enemyEscaped)
    {
        // Player's turn
        CombatAction playerAction = getPlayerAction();

        playerEscaped = resolveAction(
            playerAction,
            game.player,
            currentEnemy,
            1
        );

        // Do not give the enemy a turn if the player escaped
        // or the enemy was defeated.
        if (playerEscaped || !currentEnemy.isAlive())
        {
            break;
        }

        // Enemy's turn
        CombatAction enemyAction =
            enemyAI.chooseAction(currentEnemy, game.player);

        enemyEscaped = resolveAction(
            enemyAction,
            game.player,
            currentEnemy,
            2
        );
    }

    if (playerEscaped)
    {
        std::cout << game.player.name
            << " escaped from the "
            << currentEnemy.name << "!\n";

        currentState = GameState::Forest;
    }
    else if (enemyEscaped)
    {
        std::cout << "The " << currentEnemy.name
            << " escaped from battle!\n";

        currentState = GameState::Forest;
    }
    else if (game.player.health < 1)
    {
        std::cout << game.player.name
            << " was defeated and retreats back "
            "to the village!\n";

        game.player.health = game.player.maxHealth;
        currentState = GameState::Town;
    }
    else
    {
        std::cout << game.player.name
            << " defeated the "
            << currentEnemy.name << "!\n"
            << "You receive "
            << currentEnemy.gold << " gold!\n";

        game.player.gold += currentEnemy.gold;

        currentState = GameState::Forest;
    }
}

