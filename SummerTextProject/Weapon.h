#pragma once

#include <string>
#include <nlohmann/json.hpp>

struct Weapon
{
	std::string name;
	int damage = 0;
	int cost = 0;

};

inline void from_json(const nlohmann::json& json, Weapon& weapon)
{
	json.at("name").get_to(weapon.name);
	json.at("damage").get_to(weapon.damage);
	json.at("cost").get_to(weapon.cost);
}