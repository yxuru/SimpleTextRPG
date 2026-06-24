
#include "Player.h"
#include "Locations.h"
#include "PlayerOwnedStates.h"



int main()
{
    GameState currentState = GameState::Town;

    while (currentState != GameState::Quit)
    {
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