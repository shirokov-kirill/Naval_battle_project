#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "../include/Board.h"

//enum State
//{
//    ST_PLACING_SHIPS,
//    ST_WAITING_STEP,
//    ST_MAKING_STEP
//};

class Player {

public:
        Board board; // sorry i had to do it to make it work

  Player() noexcept;
    virtual ~Player() = default;
	Player& operator=(Player&) noexcept ;

	void increase_score(int) noexcept ;
	int get_score() noexcept ;

	void get_shot(int, int, int);
	bool can_shoot(int, int, int);

	void set_name(std::string);
	std::string get_name() noexcept ;

	bool is_alive() noexcept ;

	bool is_visible(int, int, int);
	Ships get_cell(int, int);
	bool place_ship(ShipPlacement);

	int get_cur_ship();
	void inc_ship();

	virtual bool is_bot() const noexcept;

	std::string convert_to_string();
  void set_board_from_string(std::string src);

private:

	int score;
	int combo;
	std::string name;
    int cur_ship;
};

#endif
