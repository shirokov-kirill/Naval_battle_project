#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Board.h"

class Player {
public:
	Player();
	~Player() = default;
	void increase_score(int);
	void get_shot(int, int);//понять зачем
	void set_name(std::string);
	bool is_alive();
	bool can_shoot(int, int);
private:
	Board board;
	int score;
	int combo;//на будущее, пока что не реализовано
	std::string name;
};

#endif