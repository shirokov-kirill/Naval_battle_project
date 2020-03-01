#include"Controller.h"

Controller::Controller() {
	current_player = 0;
}

Controller::~Controller(){}

void Controller::setup_player() {
	for (int i = 0; i < 2; i++) {//не обязательно 2 игрока
		players[i].set_name(interface.read_name(i));
	}
}

void Controller::game() {
	while (players[current_player].get_board().is_alive()) {
		action_game_cycle();
	}
	if (current_player % 2 != 0) {
		interface.show_winner(current_player + 1);
		return;
	}
	interface.show_winner(current_player);
}

void Controller::action_game_cycle(){
	std::pair<int, int> shot = interface.ask_shot();
	while (!players[current_player].get_board().can_shoot(shot.first, shot.second)) {
		shot = interface.ask_shot();
	}
	players[current_player].get_board().shoot(shot.first, shot.second);
	players[current_player].get_board().make_visible(shot.first, shot.second);
	current_player = (current_player++) % 2;//зависит от количества игроков
}
