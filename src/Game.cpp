#include "Game.h"
#include <iostream>

Game::Game() {
    playerPosition = "Start";
    locations["Start"] = "****You are at the start of the forest.";
    locations["Clearing"] = "****You are in a clearing with sunlight filtering through the trees.";
    locations["River"] = "****You hear the sound of water. You are at the river bank.";
    locations["Cave"] = "****It's dark inside, but you can see a faint glow. You are in a cave.";
    locations["Treasure"] = "$$$$Congratulations! You have found the hidden treasure!";
    paths["Start"]["north"] = "Clearing";
    paths["Start"]["east"] = "River";
    paths["Clearing"]["south"] = "Start";
    paths["Clearing"]["east"] = "Cave";
    paths["River"]["west"] = "Start";
    paths["Cave"]["west"] = "Clearing";
    paths["Cave"]["east"] = "Treasure";
}

void Game::start() {
	while (true) {
		displayLocation();
		std::string direction;

			if (playerPosition == "Start") std::cout << "Enter direction (north, east) or 'quit' to exit: ";
			if (playerPosition == "Clearing") std::cout << "Enter direction (south, east) or 'quit' to exit: ";
			if (playerPosition == "River") std::cout << "Enter direction (west) or 'quit' to exit: ";
			if (playerPosition == "Cave") std::cout << "Enter direction (west, east) or 'quit' to exit: ";

		std::cin >> direction;
		if (direction == "quit") break;
		move(direction);
	}
}

void Game::displayLocation() {
	std::cout << locations[playerPosition] << std::endl;
}

void Game::move(const std::string& direction) {
	if (paths[playerPosition].count(direction)) {
		playerPosition = paths[playerPosition][direction];
	} else {
		std::cout << "You can't go that way." << std::endl;
	}
}
