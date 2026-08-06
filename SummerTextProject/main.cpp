#include "Locations.h"
#include "PlayerOwnedStates.h"
#include <stdlib.h>
#include <ctime>
#include "DataManager.h"


int main()
{
    DataManager dataManager;

    if (!dataManager.LoadGameAssets())
    {
        return 1;
    }

    const std::vector<Enemy>& enemies =
        dataManager.GetEnemies();

    const std::vector<Weapon>& weapons =
        dataManager.GetWeapons();


    GameState currentState = GameState::Town;

    while (currentState != GameState::Quit)
    {
        srand(time(nullptr));
        switch (currentState)
        {
        case GameState::Town:
            Town(currentState, dataManager);
            break;

        case GameState::Forest:
            Forest(currentState, dataManager);
            break;

        case GameState::Encounter:
            
            Encounter(currentState, dataManager);
            break;
        }
    }
		return 0;
}