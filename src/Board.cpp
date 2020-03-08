#include "Board.h"

bool Board::is_sunk(std::size_t x, std::size_t y) { // TODO: out of borers guards
    if (board[x][y] == Ships::fire) {
        if (board[x - 1][y] == Ships::water &&
            board[x + 1][y] == Ships::water &&
            board[x][y - 1] == Ships::water &&
            board[x][y + 1] == Ships::water) {
            return true;
        } else if (board[x - 1][y] != Ships::water || board[x + 1][y] != Ships::water) {
            std::size_t i = 0;
            while (board[x - i][y] == Ships::fire) i++;
            if (board[x - i][y] == Ships::water) {
                std::size_t j = 0;
                while (board[x + j][y] == Ships::fire) j++;
                return board[x + j][y] == Ships::water;
            } else {
                return false;
            }
        } else if (board[x][y - 1] != Ships::water || board[x][y + 1] != Ships::water) {
            std::size_t i = 0;
            while (board[x][y - i] == Ships::fire) i++;
            if (board[x][y - i] == Ships::water) {
                std::size_t j = 0;
                while (board[x][y + j] == Ships::fire) j++;
                return board[x][y + j] == Ships::water;
            }
        }
    } else {
        return false;
    }
}

Ships Board::get_tile_status(std::size_t x, std::size_t y) {
    return board[x][y];
}

bool Board::is_alive() noexcept {
    return working_ships > 0;
}

void Board::set_H_W(std::size_t h, std::size_t w) {
    BH = h;
    BW = w;
}

Board::Board() {
    board = std::vector<std::vector<Ships >> (BH, std::vector<Ships > (BW, Ships::water));
    working_ships = 0;
    visible = std::vector<std::vector<std::bitset<PL_CNT>>> (BH, std::vector<std::bitset<PL_CNT>> (BW, 0));
}

Board::~Board() {}

void Board::place_ship(std::size_t x, std::size_t y, orientation o, Ships type) {
    if (o == orientation::horisontal) {
        for (std::size_t i = 0; i < static_cast<std::size_t >(type); i++) {
            board[x + i][y] = type;
        }
    } else if (o == orientation::vertical) {
        for (std::size_t i = 0; i < static_cast<std::size_t >(type); i++) {
            board[x][y + i] = type;
        }
    }
}

bool Board::can_place_ship(std::size_t x, std::size_t y, orientation o, Ships type) { // TODO: out of borders guards
    if (x >= BW || y >= BH) return false;
    if (o == orientation::horisontal) {
        if (x + static_cast<std::size_t >(type) < BW) {
            for (std::size_t i = x - 1; i <= x + 1 + static_cast<std::size_t >(type); i++) {
                for (std::size_t j = y - 1; j <= y + 1; j++) {
                    if (board[i][j] != Ships::water) return false;
                }
            }
            return true;
        } else return false;
    } else if (o == orientation::vertical) {
        if (y + static_cast<std::size_t >(type) < BH) {
            for (std::size_t i = x - 1; i <= x + 1; i++) {
                for (std::size_t j = y - 1; y <= y + 1 + static_cast<std::size_t >(type); j++) {
                    if (board[i][j] != Ships::water) return false;
                }
            }
            return true;
        } else return false;
    }
    return false;
}

bool Board::can_shoot(std::size_t x, std::size_t y, int player_num) {
    if (board[x][y] == Ships::fire) {
        return false;
    }
    return !visible[x][y].test(player_num);
}

void Board::get_shot(std::size_t x, std::size_t y, int player_num) { // TODO: out of borders guards
    if (board[x][y] != Ships::water) {
        board[x][y] = Ships::fire;
        if (is_sunk(x, y)){
            working_ships--;
            if (board[x - 1][y] == Ships::fire || board[x + 1][y] == Ships::fire) {
                std::size_t left = x + 1, right = x - 1;
                while (board[left][y] == Ships::fire) left++;
                while (board[right][y] == Ships::fire) right--;
                for (std::size_t i = right; i <= left; i++) {
                    for (std::size_t j = y - 1; j <= y + 1; j++) {
                        visible[i][j][player_num] = true;
                    }
                }
            } else if (board[x - 1][y] == Ships::fire || board[x + 1][y] == Ships::fire) {
                std::size_t down = y - 1, up = y + 1;
                while (board[x][down] == Ships::fire) down--;
                while (board[x][up] == Ships::fire) up++;
                for (std::size_t i = x - 1; i <= x + 1; i++) {
                    for (std::size_t j = down j <= up; j++) {
                        visible[i][j][player_num] = true;
                    }
                }
            } else {
                for (std::size_t i = x - 1; i <= x + 1; i++) {
                    for (std::size_t j = y - 1; j <= y + 1; j++) {
                        visible[i][j][player_num] = true;
                    }
                }
            }
        }
        visible[x][y] = std::bitset<PL_CNT>( 1 << PL_CNT);
    } else {
        visible[x][y][player_num] = true;
    }
}

