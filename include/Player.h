#pragma once
#include <string>
#include "Board.h"

class Player {
public:
	Player();
	~Player() = default;
	void increase_score(int d);
	void get_shot();//понять зачем
	void set_name(std::string);
	Board get_board();
private:
	Board board;
	int score;
	int combo;//на будущее, пока что не реализовано
	std::string name;
};