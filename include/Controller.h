#ifndef CONTROLLER_H
#define CONTROLLER_H

#include"Player.h"
#include <vector>

class Controller{
public:
	Controller();
	void game();
	void action_game_cycle();//добавить increase_score(каким-то образом)
	void setup_player();//добавить функцию std::string read_name(int) в Interface, добавлена void set_name(std::string) и get_board() в Player
private:
	Interface interface;
	std::vector<Player> players;
	std::vector<Player> winners;//меньше в 2 раза чем players(создан новый элемент!!!)
	int current_player;
};

#endif