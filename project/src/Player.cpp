#include"../include/Player.h"

Player::Player() noexcept {
	this->score = 0;
	this->name = "";
	this->cur_ship = 0;
}

void Player::increase_score(int d) noexcept{
	this->score += d;
}

void Player::get_shot(int x, int y, int num) {
	board.get_shot(x, y, num);
}

void Player::set_name(std::string name) {
	this->name = name;
}

std::string Player::get_name()noexcept {
	return name;
}

int Player::get_score()noexcept {
	return score;
}

bool Player::is_alive() noexcept {
	return board.is_alive();
}

bool Player::can_shoot(int x, int y, int num) {
	return board.can_shoot(x, y, num);
}


Player& Player::operator=(Player& other)noexcept {
	board = other.board;
	score = other.score;
	combo = other.combo;
	name = other.name;
	cur_ship = other.cur_ship;
	return *this;
}

bool Player::is_visible(int x, int y, int num) {
    return board.is_visible(x, y, num);
}

Ships Player::get_cell(int x, int y) {
    return board.get_tile_status(x, y);
}

bool Player::place_ship(ShipPlacement placement) {
    bool f = board.place_ship(placement);
    if(f)
        inc_ship();
    return f;
}

int Player::get_cur_ship() {
	return cur_ship;
}

void Player::inc_ship() {
	cur_ship++;
}
