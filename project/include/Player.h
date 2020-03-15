#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Board.h"

class Player {

public:
	Player()noexcept;
	~Player() = default;
	void increase_score(int)noexcept;
	void get_shot(int, int, int);//тест для Board
	void set_name(std::string);
	std::string get_name()noexcept;
	int get_score()noexcept;
	bool is_alive()noexcept;//тест для Board
	bool can_shoot(int, int, int);//тест для Board
	Player& operator=(Player&)noexcept;

private:
	Board board;
	int score;
	int combo;//на будущее, пока что не реализовано
	std::string name;

};

#endif
