#pragma once
#include <string>


enum class Enemies
{
	Goblin,
	Orge,
	Demon,
	Slime,
	EnemyFinal
};

struct Enemy
{
	std::string name;
	int health;
	int attack;
	int gold;
};

const Enemy enemyTemplates[] =
{
	{"Goblin", 10, 3, 5},
	{"Orge", 20, 5, 10},
	{"Demon", 15, 7, 12},
	{"Slime", 5, 1, 3},
};

std::string EnemyToString(Enemies enemy);
// Each enemy gets id? Then we can generate random int in the range of enum ids to get random enemy ? May need object for each or we have list of healths and give corresponding id's?