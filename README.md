# SimpleTextRPG

A work-in-progress console role-playing game written in C++. I started this project to practice structuring a larger C++ program across multiple files instead of keeping all gameplay logic in one place.

The current version focuses on game-state flow, shared player state, data-driven game assets, turn-based combat, and a first utility-based enemy decision system.

## Current Features

- State-driven game flow between a town, forest, and combat encounters
- Player health, gold, and other data that persist while moving between game states
- Random enemy selection from JSON-backed enemy definitions
- Turn-based player and enemy actions with attack and escape handling
- Utility-based enemy decisions between attacking and attempting to run
- Separate combat, enemy AI, player, enemy, data, and game-state components
- External JSON files for player, enemy, and weapon data
- Reusable templated JSON loading with `nlohmann/json`
- Central `DataManager` for loading and providing game assets

## Enemy AI

Enemies no longer automatically attack every turn. The `EnemyAI` component evaluates the current enemy and player state before choosing between `Attack` and `Run`.

The current decision model calculates:

- **Attack utility** from the enemy's remaining health as a percentage of its maximum health
- **Run utility** from the damage the player could deal relative to the enemy's current health

Running is ignored until its utility passes a minimum threshold. After that, the AI makes a weighted random choice using the two utility scores. This keeps enemy behavior from being completely predictable while making wounded enemies more likely to attempt an escape.

The selected `CombatAction` is passed into the same combat-resolution function used for player actions, keeping action selection separate from action results. This is the first version of the system and currently scores only attacking and running.

## Project Structure

The project is split into several small systems rather than one large source file:

- `main.cpp` - initializes the game, loads assets and player data, and runs the main state loop
- `PlayerOwnedStates.cpp/.h` - controls town, forest, and encounter behavior
- `Combat.cpp/.h` - defines combat actions, player input, and action-resolution logic
- `EnemyAI.cpp/.h` - evaluates utility scores and selects an enemy combat action
- `GameContext.h` - stores shared game data passed between states
- `DataManager.cpp/.h` - loads and stores reusable enemy and weapon data
- `JsonLoader.h` - templated helper for loading arrays of C++ objects from JSON
- `Player.h`, `Enemy.h`, `Weapon.h` - data structures used by the game
- `Player.json`, `Enemies.json`, `Weapons.json` - external game-data definitions

## Technologies and Concepts

- C++
- Standard Template Library, including `std::vector`
- Object-oriented and modular program design
- State-driven program flow
- Utility-based game AI
- Weighted randomized decision-making
- Separation of decision logic from action resolution
- File I/O and JSON parsing
- Function templates
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

This project is actively in development and is not intended to be a finished game yet. The basic game-state loop, shared player state, JSON-backed data, combat flow, and first enemy AI implementation are working, while combat depth and progression are still being expanded and refactored.

## Planned Improvements

- Add more meaningful combat choices and finish the defend and item actions
- Expand the utility system to evaluate additional enemy actions
- Tune the attack and run utility calculations through playtesting
- Add different enemy behaviors or personality weights
- Add usable weapons, items, and a functioning shop
- Improve input validation and error handling
- Add more locations and progression systems
- Continue separating gameplay systems into reusable components

## Why I Built This

My main goal with this project is to get more comfortable designing a program with persistent state and multiple interacting systems. It has given me practice with C++ project organization, external data files, reusable loaders, game-state management, and separating AI decision-making from combat execution.
