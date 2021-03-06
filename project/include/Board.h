#ifndef BOARD_H_NAVAL
#define BOARD_H_NAVAL

#include <cstdlib>
#include <bitset>
#include <vector>
#include <string>

#include "ShipPlacement.h"

// static const std::size_t BH = 10, BW = 10;
// static const std::size_t BHA = BH + 2, BWA = BW + 2;


class Board {
public:
    Board();
    ~Board();
    Board(const Board& other);
    Board& operator=(Board& other) noexcept ;

    std::size_t BH, BW;
    std::size_t BHA, BWA;

    bool can_place_ship(ShipPlacement placement);
    bool place_ship(ShipPlacement placement);

    Ships get_tile_status(std::size_t, std::size_t);
    bool is_visible(std::size_t x, std::size_t y, int player_num) const ;

    bool can_shoot(std::size_t x, std::size_t y, int player_num);
    void get_shot(std::size_t x, std::size_t y, int player_num);

    bool is_alive() noexcept;

    void set_tile_status(std::size_t x, std::size_t y, Ships type); // temporary thing dunno how to do it other way for now

private:

    std::vector<std::vector<Ships>> board;
    int working_ships;
    std::vector<std::vector<std::bitset<PL_CNT>>> visible;

    bool is_sunk(std::size_t, std::size_t);
};

#endif
