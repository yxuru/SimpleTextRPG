#include "Enemy.h"
#include <string>
#include "PlayerOwnedStates.h"


std::string EnemyToString(Enemies enemy)
{
    switch (enemy)
    {
    case Enemies::Slime: return "Slime";
    case Enemies::Goblin: return "Goblin";
    case Enemies::Orge: return "Ogre";
    case Enemies::Demon: return "Demon";
    default: return "Unknown";
    }
}

