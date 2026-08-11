#include "Combat.h"
#include <vector>
#include "GameContext.h"




void resolveAction(CombatAction action, Player player, Enemy enemy, int turn)
{
	if (turn == 1)
	{
		switch (action)
		{
		case CombatAction::Attack:
			std::cout << player.name << " attacks " << enemy.name << " for " << player.attack << " damage!\n";
			player.health -= enemy.attack;
		case CombatAction::Defend:
			std::cout << "Player Defends\n";
		case CombatAction::Run:
			std::cout << "Player Runs\n";
		case CombatAction::Item:
			std::cout << "Player uses item\n";

		}
	}
	else if (turn == 2)
	{
		switch (action) 
		{
			case CombatAction::Attack:
				std::cout << enemy.name << " attacks " << player.name << " for " << enemy.attack << " damage!\n";
				enemy.health -= player.attack;
			case CombatAction::Defend:
				std::cout << "Enemy Defends\n";
			case CombatAction::Run: 
				std::cout << "Enemy Runs\n";
			case CombatAction::Item:
				std::cout << "Enemy uses item\n";
		}
	}
}