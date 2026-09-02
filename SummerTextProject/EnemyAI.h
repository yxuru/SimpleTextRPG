#pragma once
#include "Combat.h"

struct Enemy;
struct Player;

class EnemyAI
{
public:
    CombatAction chooseAction(
        const Enemy& enemy,
        const Player& player
    ) const;
};
