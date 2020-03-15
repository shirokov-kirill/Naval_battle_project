#include"Player.h"

Player::Player() noexcept {
	this->score = 0;
	this->name = "";
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
	return *this;
}