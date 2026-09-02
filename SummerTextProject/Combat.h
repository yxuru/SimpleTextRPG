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

CombatAction getPlayerAction();

bool resolveAction(CombatAction action, Player& player, Enemy& enemy, int turn);