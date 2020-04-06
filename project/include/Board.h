#ifndef BOARD_H_NAVAL
#define BOARD_H_NAVAL

#include <cstdlib>
#include <bitset>
#include <vector>

#include "ShipPlacement.h"

static std::size_t BH, BW;
static const int  PL_CNT = 2;

class Board {
public:
    bool can_place_ship(ShipPlacement placement);
    void place_ship(ShipPlacement placement);

    Ships get_tile_status(std::size_t, std::size_t) const ;
	bool get_visuality_status(std::size_t x, std::size_t y, int player_num) const ;

    bool can_shoot(std::size_t x, std::size_t y, int player_num);
    void get_shot(std::size_t x, std::size_t y, int player_num);

    bool is_alive() noexcept;

    void set_H_W(std::size_t h, std::size_t w);

    Board();
    ~Board();
    Board(const Board& other);
    Board& operator=(Board& other) noexcept ;

private:
    std::vector<std::vector<Ships>> board;
    int working_ships;
    std::vector<std::vector<std::bitset<PL_CNT>>> visible;

    bool is_sunk(std::size_t, std::size_t);
};

#endif