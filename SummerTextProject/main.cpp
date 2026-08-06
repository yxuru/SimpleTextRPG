#include "Locations.h"
#include "PlayerOwnedStates.h"
#include <stdlib.h>
#include <ctime>
#include "GameContext.h"
#include "JsonLoader.h"
#include <iostream>


int main()
{
    GameContext game;

    if (!game.assets.LoadGameAssets())
    {
        return 1;
    }

    try
    {
        std::vector<Player> characters =
            LoadJsonArray<Player>("Player.json");

        if (characters.empty())
        {
            std::cout << "No characters found.\n";
            return 1;
        }

        game.player = characters.at(0);
    }
    catch (const std::exception& error)
    {
        std::cerr
            << "Failed to load player: "
            << error.what()
            << '\n';

        return 1;
    }

    GameState currentState = GameState::Town;

    while (currentState != GameState::Quit)
    {
        srand(time(nullptr));
        switch (currentState)
        {
        case GameState::Town:
            Town(currentState, game);
            break;

        case GameState::Forest:
            Forest(currentState, game);
            break;

        case GameState::Encounter:
            
            Encounter(currentState, game);
            break;
        }
    }
		return 0;
}