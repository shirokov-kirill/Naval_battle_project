#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Board.h"

class Player {

public:
	Player()noexcept;
	~Player() = default;
	void increase_score(int)noexcept;
	void get_shot(int, int, int);//���� ��� Board
	void set_name(std::string);
	std::string get_name()noexcept;
	int get_score()noexcept;
	bool is_alive()noexcept;//���� ��� Board
	bool can_shoot(int, int, int);//���� ��� Board
	Player& operator=(Player&)noexcept;
	bool is_visible(int, int, int);
	Ships get_cell(int, int);

private:
	Board board;
	int score;
	int combo;//�� �������, ���� ��� �� �����������
	std::string name;

};

#endif
