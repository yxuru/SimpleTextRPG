#pragma once
#include <iostream>
#include "GameContext.h"
enum class CombatAction {
	Attack,
	Defend,
	Run,
	Item,
	COUNT
};

constexpr std::string_view toString(CombatAction action)
{
	switch (action)
	{
		case CombatAction::Attack: return "Attack";
		case CombatAction::Defend: return "Defend";
		case CombatAction::Run: return "Run";
		case CombatAction::Item: return "Use Item";
	}

	return "Unknown";
}

CombatAction getPlayerAction() {
	std::cout << "Choose your move!\n";
	for (int i = 0; i < static_cast<int>(CombatAction::COUNT); ++i)
	{
		CombatAction action = static_cast<CombatAction>(i);
		std::cout << i + 1 << ". " << toString(action);
	}

	int choice;

	while (true)
	{
		std::cout << "> ";

		if (std::cin >> choice && choice > 0 && choice < static_cast<int>(CombatAction::COUNT))
		{
			return static_cast<CombatAction>(choice - 1);
		}

		std::cout << "Please enter a valid choice.\n";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
}

void resolveAction(CombatAction action, Player player, Enemy enemy, int turn);