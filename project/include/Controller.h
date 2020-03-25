#ifndef CONTROLLER_H
#define CONTROLLER_H

#include"Player.h"
#include "Interface.h"
#include <vector>

class Controller{

public:
	Controller();
	void game();
	void action_game_cycle();
	void setup_player();

private:
	Interface interface;
	std::vector<Player> players;
	std::vector<Player> winners;
	int current_player;

};

#endif