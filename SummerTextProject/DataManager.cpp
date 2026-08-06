#include "DataManager.h"

#include <exception>
#include <iostream>

#include "JsonLoader.h"

bool DataManager::LoadGameAssets()
{
    try
    {
        enemies =
            LoadJsonArray<Enemy>("Enemies.json");

        weapons =
            LoadJsonArray<Weapon>("Weapons.json");

        return true;
    }
    catch (const std::exception& error)
    {
        std::cerr
            << "Asset loading failed: "
            << error.what()
            << '\n';

        return false;
    }
}

const std::vector<Enemy>& DataManager::GetEnemies() const
{
    return enemies;
}

const std::vector<Weapon>& DataManager::GetWeapons() const
{
    return weapons;
}