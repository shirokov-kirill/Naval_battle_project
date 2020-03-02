#include"Player.h"

Player::Player() {
	this->score = 0;
	this->name = "";
}

void Player::increase_score(int d) {
	this->score += d;
}

void Player::get_shot()
{

}

void Player::set_name(std::string name) {
	this->name = name;
}

Board Player::get_board()
{
	return board;
}
