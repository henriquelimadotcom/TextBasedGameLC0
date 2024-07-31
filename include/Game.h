#ifndef GAME_H
#define GAME_H

#include <string>
#include <map>

class Game {
private:
	std::string playerPosition;
	std::map<std::string, std::string> locations;
	std::map<std::string, std::map<std::string, std::string>> paths;

public:
	Game();
	void start();
	void displayLocation();
	void move(const std::& direction);
};

#endif
