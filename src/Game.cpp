#include "Game.h"
#include <iostream>

Game::Game() {
    playerPosition = "Start";
    locations["Start"] = "You are at the start of the forest.";
    locations["Clearing"] = "You are in a clearing with sunlight filtering through the trees.";
    locations["River"] = "You hear the sound of water. You are at the river bank.";
    locations["Cave"] = "It's dark inside, but you can see a faint glow. You are in a cave.";
    locations["Treasure"] = "Congratulations! You have found the hidden treasure!";
    paths["Start"]["North"] = "Clearing";
    paths["Start"]["East"] = "River";
    paths["Clearing"]["South"] = "Start";
    paths["Clearing"]["East"] = "Cave";
    paths["River"]["West"] = "Start";
    paths["Cave"]["West"] = "Clearing";
    paths["Cave"]["East"] = "Treasure";
}

void Game::start() {
	while (true) {
		displayLocation();
		std::string direction;
		std::cout << "Enter direction (North, South, East, West) or 'quit' to exit: ";
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
