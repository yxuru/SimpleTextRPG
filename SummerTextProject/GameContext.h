#pragma once
#include "DataManager.h"
#include "Player.h"

struct GameContext {
	DataManager assets;
	Player player;
};