#pragma once


enum class GameState
{
	Town,
	Forest,
	Encounter,
	Quit
};


void Town(GameState& currentState);
void Forest(GameState& currentState);
void Encounter(GameState& currentState);