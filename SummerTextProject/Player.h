#pragma once
#include <string>
#include <nlohmann/json.hpp>

struct Player
{
	std::string name;
	int health;
	int maxHealth;
	int defense;
	int attack;
	int gold;
};


inline void from_json(const nlohmann::json& json, Player& player)
{
	json.at("name").get_to(player.name);
	json.at("health").get_to(player.health);
	json.at("health").get_to(player.maxHealth);
	json.at("defense").get_to(player.defense);
	json.at("attack").get_to(player.attack);
	json.at("gold").get_to(player.gold);
}