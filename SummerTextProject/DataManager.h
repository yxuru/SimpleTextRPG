#pragma once

#include <vector>

#include "Enemy.h"
#include "Weapon.h"

class DataManager
{
public:
    bool LoadGameAssets();

    const std::vector<Enemy>& GetEnemies() const;
    const std::vector<Weapon>& GetWeapons() const;

private:
    std::vector<Enemy> enemies;
    std::vector<Weapon> weapons;
};