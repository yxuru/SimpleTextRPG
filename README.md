# SimpleTextRPG

A work-in-progress console role-playing game written in C++. I started this project to practice structuring a larger C++ program across multiple files instead of keeping all gameplay logic in one place.

The current version focuses on game-state flow, shared player state, data-driven game assets, and a developing turn-based combat system.

## Current Features

- State-driven game flow between a town, forest, and combat encounters
- Player data that persists while moving between game states
- Random enemy selection from loaded enemy definitions
- Separate combat, player, enemy, and game-state components
- External JSON files for player, enemy, and weapon data
- Reusable templated JSON loading with `nlohmann/json`
- Central `DataManager` for loading and providing game assets

## Project Structure

The project is split into several small systems rather than one large source file:

- `main.cpp` - initializes the game, loads assets/player data, and runs the main state loop
- `PlayerOwnedStates.cpp/.h` - town, forest, and encounter state behavior
- `Combat.cpp/.h` - combat actions and combat resolution logic
- `GameContext.h` - shared game data passed between states
- `DataManager.cpp/.h` - loads and stores reusable enemy and weapon data
- `JsonLoader.h` - templated helper for loading arrays of C++ objects from JSON
- `Player.h`, `Enemy.h`, `Weapon.h` - data structures used by the game
- `Player.json`, `Enemies.json`, `Weapons.json` - external game-data definitions

## Technologies and Concepts

- C++
- Standard Template Library (`std::vector`, enums, etc.)
- Object-oriented and modular program design
- State-driven program flow
- File I/O and JSON parsing
- Templates
- Data-driven game design
- Visual Studio
- `nlohmann/json`

## Building and Running

The repository is currently set up as a Visual Studio C++ project on Windows.

1. Clone the repository.
2. Open `SimpleTextRPG.slnx` in Visual Studio.
3. Build the project.
4. Run the project with the JSON data files available in the program's working directory.

The `nlohmann/json` headers used by the project are included under the project's `ThirdParty` directory.

## Status

This project is actively in development and is not intended to be a finished game yet. Some gameplay systems, especially combat and progression, are still being expanded and refactored.

## Planned Improvements

- Finish and refine the turn-based combat system
- Expand enemy behavior and combat choices
- Add usable weapons/items and a functioning shop
- Improve input validation and error handling
- Add more locations and progression systems
- Continue separating gameplay systems into reusable components

## Why I Built This

My main goal with this project is to get more comfortable designing a program that has persistent state and multiple interacting systems. It has also given me practice working with C++ project organization, external data files, reusable loaders, and game-oriented state management.
