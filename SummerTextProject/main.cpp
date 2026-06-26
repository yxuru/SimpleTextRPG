
#include "Player.h"
#include "Locations.h"
#include "PlayerOwnedStates.h"
#include <stdlib.h>
#include <ctime>



int main()
{
    GameState currentState = GameState::Town;

    while (currentState != GameState::Quit)
    {
        srand(time(nullptr));
        switch (currentState)
        {
        case GameState::Town:
            Town(currentState);
            break;

        case GameState::Forest:
            Forest(currentState);
            break;

        case GameState::Encounter:
            
            Encounter(currentState);
            break;
        }
    }
		return 0;
}