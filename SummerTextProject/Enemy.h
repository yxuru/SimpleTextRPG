#pragma once
#include <string>
#include <nlohmann/json.hpp>

struct Enemy
{
	std::string name;
	int health;
	int attack;
	int gold;

	bool isAlive() const
	{
		return health > 0;
	}

};


inline void from_json(const nlohmann::json& json, Enemy& enemy)
{
	json.at("name").get_to(enemy.name);
	json.at("health").get_to(enemy.health);
	json.at("attack").get_to(enemy.attack);
	json.at("gold").get_to(enemy.gold);
}