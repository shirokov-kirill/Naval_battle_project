#include "../include/Bot.h"

#include <random>
#include <vector>
#include <algorithm>
#include <time.h>

bool Bot::is_bot() const noexcept {
    return true;
}

std::mt19937 rnd(time(0));

std::pair<int, int> Bot::make_fight_step(Player *other_player) {
    bool pic_new = false;
    if (current_ship_target != std::make_pair(0, 0) && other_player->get_cell(current_ship_target.first, current_ship_target.second) != Ships::water) {
           std::pair<int, int> next_shot;
           if (!other_player->is_visible(current_ship_target.first + 1, current_ship_target.second, 1)) {
               next_shot = {current_ship_target.first + 1, current_ship_target.second};
           } else if (!other_player->is_visible(current_ship_target.first - 1, current_ship_target.second, 1)) {
               next_shot = {current_ship_target.first - 1, current_ship_target.second};
           } else if (!other_player->is_visible(current_ship_target.first, current_ship_target.second + 1, 1)) {
               next_shot = {current_ship_target.first, current_ship_target.second + 1};
           } else if (!other_player->is_visible(current_ship_target.first, current_ship_target.second - 1, 1)) {
               next_shot = {current_ship_target.first, current_ship_target.second - 1};
           }
           if (current_ship_target != next_shot) current_ship_target = next_shot;
           else pic_new = true;
    } else if (current_ship_target == std::make_pair(0, 0) || other_player->get_cell(current_ship_target.first, current_ship_target.second) == Ships::water || pic_new) {
        std::pair<int, int> tmp = current_ship_target;
        int i = 0;
        do {
            current_ship_target.first = (rnd() % 10) + 1;  // 10 must be changed later to custom value
            current_ship_target.second = (rnd() % 10) + 1;
            i++;
        } while (i < 12 && other_player->is_visible(current_ship_target.first, current_ship_target.second, 1));
        if (current_ship_target == tmp){
            for (int k = 1; k <= 10; k++) {
                if (!other_player->is_visible(k, k, 1)) {
                    current_ship_target = {k, k};
                    break;
                }
            }
            if (current_ship_target == tmp) {
                for (int k = 10; k > 0; k--) {
                    for (int l = 1; l <= 10; l++) {
                        if (!other_player->is_visible(k, l, 1)) {
                            current_ship_target = {k, l};
                            break;
                        }
                    }
                }
                if (current_ship_target == tmp) {
                    for (int k = 1; k <= 10; k++) {
                        for (int l = 1; l <= 10; l++) {
                            if (!other_player->is_visible(k, l, 1)) {
                                current_ship_target = {k, l};
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return current_ship_target;
}

void Bot::make_placement() {
    int key;
    std::vector<Ships> ships = {Ships::carrier, Ships::regular, Ships::regular, Ships::middle, Ships::middle, Ships::middle, Ships::small, Ships::small, Ships::small, Ships::small};
    std::random_shuffle(ships.begin(), ships.end());
    int next = 0;
    while (next < 9) {
        key = rnd() % 4;
        switch (key) {
            case 0:
                for (int i = 1; i <= 10; i += 2) {
                    ShipPlacement tmp(i, i, static_cast<orientation>(rnd()%2), ships.at(next));
                    if (this->can_place_ship(tmp)) {
                        next++;
                        this->place_ship(tmp);
                        if (next == 10) break;
                    }
                }
                for (int i = 9; i > 1; i -= 2) {
                    ShipPlacement tmp(i, i, static_cast<orientation>(rnd()%2), ships.at(next));
                    if (this->can_place_ship(tmp)) {
                        next++;
                        this->place_ship(tmp);
                        if (next == 10) break;
                    }
                }
                break;
            case 1:
                for (int i = 2; i <= 10; i += 2) {
                    ShipPlacement tmp(i, i, static_cast<orientation>(rnd()%2), ships.at(next));
                    if (this->can_place_ship(tmp)) {
                        next++;
                        this->place_ship(tmp);
                        if (next == 10) break;
                    }
                }
                for (int i = 10; i > 1; i -= 2) {
                    ShipPlacement tmp(i, i, static_cast<orientation>(rnd()%2), ships.at(next));
                    if (this->can_place_ship(tmp)) {
                        next++;
                        this->place_ship(tmp);
                        if (next == 10) break;
                    }
                }
                break;
            case 2:
                for (int i = 1; i <= 10; i += 2) {
                    ShipPlacement tmp(i, 5 + (rnd()%10 - 4), static_cast<orientation>(rnd()%2), ships.at(next));
                    if (this->can_place_ship(tmp)) {
                        next++;
                        this->place_ship(tmp);
                        if (next == 10) break;
                    }
                }
                break;
            case 3:
                for (int i = 1; i <= 10; i += 2) {
                    ShipPlacement tmp(5 + (rnd()%10 - 4), i, static_cast<orientation>(rnd()%2), ships.at(next));
                    if (this->can_place_ship(tmp)) {
                        next++;
                        this->place_ship(tmp);
                        if (next == 10) break;
                    }
                }
                break;
        }
    }
}
