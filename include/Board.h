#ifndef BOARD_H_NAVAL
#define BOARD_H_NAVAL

#include <cstdlib>
#include <bitset>
#include <vector>

enum class Ships {
    fire = -1,
    water = 0,
    small = 1,
    middle = 2,
    regular = 3,
    carrier = 4
};

enum class orientation {
    horisontal = 0,
    vertical = 1,
};

static std::size_t BH, BW;
static const int  PL_CNT = 2;

class Board {
private:
    std::vector<std::vector<Ships>> board;
    int working_ships;
    std::vector<std::vector<std::bitset<PL_CNT>>> visible;

    bool is_sunk(std::size_t, std::size_t);

public:
    bool can_place_ship(std::size_t x, std::size_t y, orientation o, Ships type);
    void place_ship(std::size_t x, std::size_t y, orientation o, Ships type);

    Ships get_tile_status(std::size_t, std::size_t);

    bool can_shoot(std::size_t x, std::size_t y, int player_num);
    void get_shot(std::size_t x, std::size_t y, int player_num);

    bool is_alive() noexcept;

    void set_H_W(std::size_t h, std::size_t w);

    Board();
    ~Board();
    Board(const Board& other) = delete;
    Board operator=(Board& other) = delete;

};

#endif