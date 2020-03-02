#pragma once
#include"Player.h"

class Controller{
public:
	Controller();
	void game();
	void action_game_cycle();//добавить increase_score(каким-то образом)
	void setup_player();//добавить функцию std::string read_name(int) в Interface, добавлена void set_name(std::string) и get_board() в Player
private:
	Interface interface;
	Player players[2];
	Player winners[1];//меньше в 2 раза чем players(создан новый элемент!!!)
	int current_player;
};