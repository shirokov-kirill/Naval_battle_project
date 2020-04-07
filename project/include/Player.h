#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "../include/Board.h"

enum State
{
    ST_PLACING_SHIPS,
    ST_WAITING_STEP,
    ST_MAKING_STEP
};

class Player {

public:
	Player()noexcept;
	~Player() = default;
	void increase_score(int)noexcept;
	void get_shot(int, int, int);
	void set_name(std::string);
	std::string get_name()noexcept;
	int get_score()noexcept;
	bool is_alive()noexcept;
	bool can_shoot(int, int, int);
	Player& operator=(Player&)noexcept;
	bool is_visible(int, int, int);
	Ships get_cell(int, int);
	bool place_ship(ShipPlacement);
	int get_cur_ship();
	void inc_ship();
	State getState();
	void setState(State);

private:
	State state; //zaebalo...

private:
	Board board;
	int score;
	int combo;
	std::string name;
	int cur_ship;
};

#endif
