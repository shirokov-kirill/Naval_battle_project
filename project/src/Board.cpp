#include "../include/Board.h"
#include <iostream>

bool Board::is_sunk(std::size_t x, std::size_t y) {
    if (board[x][y] == Ships::fire) {
        if (board[x - 1][y] == Ships::water &&
            board[x + 1][y] == Ships::water &&
            board[x][y - 1] == Ships::water &&
            board[x][y + 1] == Ships::water) {
            board[x][y] = Ships::drownen_ship;
            return true;
        } else if (board[x - 1][y] != Ships::water || board[x + 1][y] != Ships::water) {
            std::size_t i = 0;
            while (board[x - i][y] == Ships::fire) i++;
            if (board[x - i][y] == Ships::water) {
                std::size_t j = 0;
                while (board[x + j][y] == Ships::fire) j++;
                if (board[x + j][y] == Ships::water) {
                    j--;
                    while (board[x + j][y] == Ships::fire) {
                        board[x + j][y] = Ships::drownen_ship;
                        j--;
                    }
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else if (board[x][y - 1] != Ships::water || board[x][y + 1] != Ships::water) {
            std::size_t i = 0;
            while (board[x][y - i] == Ships::fire) i++;
            if (board[x][y - i] == Ships::water) {
                std::size_t j = 0;
                while (board[x][y + j] == Ships::fire) j++;
                if(board[x][y + j] == Ships::water) {
                    j--;
                    while (board[x][y + j] == Ships::fire) {
                        board[x][y + j] = Ships::drownen_ship;
                        j--;
                    }
                    return true;
                } else {
                    return false;
                }
            }
        }
    } else {
        return false;
    }
}

Ships Board::get_tile_status(std::size_t x, std::size_t y) { return board.at(x).at(y); }

bool Board::is_visible(std::size_t x, std::size_t y, int player_num) const { return visible.at(x).at(y)[player_num]; }

bool Board::is_alive() noexcept {
    return working_ships > 0;
}

Board::Board() {
    //// hardcoded for now
    BH = 10;
    BW = 10;
    //// --------

    BHA = BH + 2;
    BWA = BW + 2;

    board = std::vector<std::vector<Ships >> (BHA, std::vector<Ships > (BWA, Ships::water));
    working_ships = 0;
    visible = std::vector<std::vector<std::bitset<PL_CNT>>> (BHA, std::vector<std::bitset<PL_CNT>> (BWA, 0));
}

Board::~Board() {}

Board::Board(const Board& other) {
    BH = other.BH;
    BW = other.BW;
    BWA = other.BWA;
    BHA = other.BHA;
    board = std::vector<std::vector<Ships >>(BHA, std::vector<Ships >(BWA));
    for (std::size_t i = 0; i < BHA; i++) {
        for (std::size_t j = 0; j < BWA; j++) {
            board.at(i).at(j) = other.board.at(i).at(j);
        }
    }
    working_ships = other.working_ships;
    visible = std::vector<std::vector<std::bitset<PL_CNT>>>(BHA, std::vector<std::bitset<PL_CNT>>(BWA));
    for (std::size_t i = 0; i < BHA; i++) {
        for (std::size_t j = 0; j < BWA; j++) {
            visible.at(i).at(j) = other.visible.at(i).at(j);
        }
    }
}

Board& Board::operator=(Board& other) noexcept {
    BH = other.BH;
    BW = other.BW;
    BWA = other.BWA;
    BHA = other.BHA;
    board = std::vector<std::vector<Ships >>(BHA, std::vector<Ships >(BWA));
    for (std::size_t i = 0; i < BHA; i++) {
        for (std::size_t j = 0; j < BWA; j++) {
            board.at(i).at(j) = other.board.at(i).at(j);
        }
    }
    working_ships = other.working_ships;
    for (std::size_t i = 0; i < BHA; i++) {
        for (std::size_t j = 0; j < BWA; j++) {
            visible.at(i).at(j) = other.visible.at(i).at(j);
        }
    }
    return *this;
}

bool Board::place_ship(ShipPlacement placement) {
    if (can_place_ship(placement)) {
        if (placement.orient == orientation::vertical) {
            for (std::size_t i = 0; i < static_cast<std::size_t >(placement.type); i++) {
                board[placement.x][placement.y + i] = placement.type;
            }
        } else if (placement.orient == orientation::horizontal) {
            for (std::size_t i = 0; i < static_cast<std::size_t >(placement.type); i++) {
                board[placement.x + i][placement.y] = placement.type;
            }
        }
        working_ships++;
        return true;
    }
    return false;
}

bool Board::can_place_ship(ShipPlacement placement) {
    if (std::size_t(placement.x) == 0 || std::size_t(placement.y) == 0) return false;
    if (placement.orient == orientation::horizontal) {
        if (std::size_t(placement.x) + static_cast<std::size_t >(placement.type) - 1 <= BW) {
            for (std::size_t i = std::size_t(placement.x) - 1; i <= std::size_t(placement.x) + static_cast<std::size_t >(placement.type); i++) {
                for (std::size_t j = std::size_t(placement.y) - 1; j <= std::size_t(placement.y) + 1; j++) {
                    if (board.at(i).at(j) != Ships::water) return false;
                }
            }
            return true;
        } else return false;
    } else if (placement.orient == orientation::vertical) {
        if (std::size_t(placement.y) + static_cast<std::size_t >(placement.type) - 1 <= BH) {
            for (std::size_t i = std::size_t(placement.x) - 1; i <= std::size_t(placement.x) + 1; i++) {
                for (std::size_t j = std::size_t(placement.y) - 1; j <= std::size_t(placement.y) + static_cast<std::size_t >(placement.type); j++) {
                    if (board.at(i).at(j) != Ships::water) return false;
                }
            }
            return true;
        } else return false;
    }
    return false;
}

bool Board::can_shoot(std::size_t x, std::size_t y, int player_num) {
    if (board.at(x).at(y) == Ships::fire) {
        return false;
    }
    return (!visible.at(x).at(y).test(player_num) && (x > 0 && y > 0 && x < 11 && y < 11));
}

void Board::get_shot(std::size_t x, std::size_t y, int player_num) {
    visible.at(x).at(y)[player_num] = true;  // needed for now when 2 players only
    if (board.at(x).at(y) != Ships::water && board.at(x).at(y) != Ships::drownen_ship) {
        board.at(x).at(y) = Ships::fire;
        if (is_sunk(x, y)){
            working_ships--;
            if (board.at(x - 1).at(y) == Ships::drownen_ship || board.at(x + 1).at(y) == Ships::drownen_ship) {
                std::size_t left = x + 1, right = x - 1;
                while (board.at(left).at(y) == Ships::drownen_ship) left++;
                while (board.at(right).at(y) == Ships::drownen_ship) right--;
                for (std::size_t i = right; i <= left; i++) {
                    for (std::size_t j = y - 1; j <= y + 1; j++) {
                        visible.at(i).at(j)[player_num] = true;
                    }
                }
            } else if (board.at(x).at(y - 1) == Ships::drownen_ship || board.at(x).at(y + 1) == Ships::drownen_ship) {
                std::size_t down = y - 1, up = y + 1;
                while (board.at(x).at(down) == Ships::drownen_ship) down--;
                while (board.at(x).at(up) == Ships::drownen_ship) up++;
                for (std::size_t i = x - 1; i <= x + 1; i++) {
                    for (std::size_t j = down; j <= up; j++) {
                        visible.at(i).at(j)[player_num] = true;
                    }
                }
            } else {
                for (std::size_t i = x - 1; i <= x + 1; i++) {
                    for (std::size_t j = y - 1; j <= y + 1; j++) {
                        visible.at(i).at(j)[player_num] = true;
                    }
                }
            }
        }
        visible.at(x).at(y)[player_num] = true;
    }
//    visible.at(x).at(y) = std::bitset<PL_CNT>( 1 << PL_CNT);
}

void Board::set_tile_status(std::size_t x, std::size_t y, Ships type) {
    board.at(x).at(y) = type;
}
