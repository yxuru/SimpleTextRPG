#include "EnemyAI.h"



CombatAction EnemyAI::chooseAction(const Enemy& enemy, const Player& player) const
{
    double attackUtil =
        static_cast<double>(enemy.health) / enemy.maxHealth;

    double runUtil =
        0.5 * (1.0 -
            static_cast<double>(enemy.health - player.attack)
            / enemy.health);

    // Running isn't considered unless its utility is high enough.
    if (runUtil <= 0.2)
    {
        return CombatAction::Attack;
    }

    double totalUtility = attackUtil + runUtil;

    double randomFraction =
        static_cast<double>(rand()) / RAND_MAX;

    double roll = randomFraction * totalUtility;

    if (roll < attackUtil)
    {
        return CombatAction::Attack;
    }

    return CombatAction::Run;
}