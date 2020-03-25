#include"Controller.h"

Controller::Controller() {
	players.resize(2);
	winners.resize(1);
	current_player = 0;
}

Controller::~Controller(){}

void Controller::setup_player() {
	for (int i = 0; i < 2; i++) {
		players[i].set_name(interface.read_name(i));
	}
}

void Controller::game() {
	while (players[current_player].is_alive()) {
		action_game_cycle();
	}
	if (current_player == 0){
		winners[(players.size()-1) / 2] = players[2];
		return;
	}
	winners[(current_player - 1) / 2] = players[current_player - 1];
}

void Controller::action_game_cycle(){
	std::pair<int, int> shot = interface.ask_shot();
	while (!players[current_player % 2 == 0 ? current_player+1 : current_player - 1].can_shoot(shot.first, shot.second, current_player % 2 == 0 ? current_player + 1 : current_player - 1)) {
		interface.show_error("incorrect turn");
		shot = interface.ask_shot();
	}
	players[current_player % 2 == 0 ? current_player + 1 : current_player - 1].get_shot(shot.first, shot.second, current_player % 2 == 0 ? current_player + 1 : current_player - 1);
	current_player = (current_player + 1) % 2;//�� 2
}