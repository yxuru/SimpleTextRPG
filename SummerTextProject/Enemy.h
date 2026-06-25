#pragma once



enum class Enemies
{
	Goblin,
	Orge,
	Demon,
	Slime,
	EnemyFinal
};

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

// Each enemy gets id? Then we can generate random int in the range of enum ids to get random enemy ? May need object for each or we have list of healths and give corresponding id's?