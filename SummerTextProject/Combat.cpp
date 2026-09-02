#include "Combat.h"
#include <vector>
#include "GameContext.h"

CombatAction getPlayerAction() {
	std::cout << "Choose your move!\n";
	for (int i = 0; i < static_cast<int>(CombatAction::COUNT); ++i)
	{
		CombatAction action = static_cast<CombatAction>(i);
		std::cout << i + 1 << ". " << toString(action) << std::endl;
	}

	int choice;

	while (true)
	{
		std::cout << "> ";

		if (std::cin >> choice && choice > 0 && choice <= static_cast<int>(CombatAction::COUNT))
		{
			return static_cast<CombatAction>(choice - 1);
		}

		std::cout << "Please enter a valid choice.\n";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
}


bool resolveAction(CombatAction action, Player& player, Enemy& enemy, int turn)
{
	if (turn == 1)
	{
		switch (action)
		{
		case CombatAction::Attack:
			std::cout << player.name << " attacks " << enemy.name << " for " << player.attack << " damage!\n";
			enemy.health -= player.attack;
			break;
		case CombatAction::Defend:
			std::cout << "Player Defends\n";

			break;
		case CombatAction::Run:
		{
			std::cout << "Player Runs\n";
			int runRoll = rand() % 100;

			if (runRoll < 50)
			{
				std::cout << player.name << " successfully escaped!\n";
				return true;
			}

			std::cout << player.name << " failed to escape!\n";
			return false;
		}
		case CombatAction::Item:
			std::cout << "Player uses item\n";

			break;
		
		}
		return false;
	}
	else if (turn == 2)
	{
		switch (action)
		{
		case CombatAction::Attack:
			std::cout << enemy.name << " attacks " << player.name << " for " << enemy.attack << " damage!\n";
			player.health -= enemy.attack;
			break;
		case CombatAction::Defend:
			std::cout << "Enemy Defends\n";

			break;
		case CombatAction::Run:
		{
			std::cout << "Enemy Runs\n";
			int runRoll = rand() % 100;

			if (runRoll < 50)
			{
				std::cout << enemy.name << " successfully escaped!\n";
				return true;
			}

			std::cout << enemy.name << " failed to escape!\n";
			return false;
		}
		case CombatAction::Item:
			std::cout << "Enemy uses item\n";

			break;

		}
		return false;
	}
}