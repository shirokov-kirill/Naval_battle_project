#include"Player.h"

Player::Player() {
	this->score = 0;
	this->name = "";
}

void Player::increase_score(int d) {
	this->score += d;
}

void Player::get_shot(int x, int y){
	board.make_visible(x, y);
	if (board.is_sunk()){
		board.decr_working_ships();
	}
}

void Player::set_name(std::string name){
	this->name = name;
}

bool Player::is_alive(){
	return board.is_alive();
}

bool Player::can_shoot(int x, int y){
	return board.can_shoot(x, y);
}
