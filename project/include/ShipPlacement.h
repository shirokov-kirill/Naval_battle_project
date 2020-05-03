#ifndef NAVAL_BATTLE_SHIP_PLACEMENT_H
#define NAVAL_BATTLE_SHIP_PLACEMENT_H


enum class Ships {
    drownen_ship = -420,
    fire = -1,
    water = 0,
    shore = 10,
    grassy_land = 11,
    hills = 12,
    small = 1,
    middle = 2,
    regular = 3,
    carrier = 4
};

enum class orientation {
    horizontal = 0,
    vertical = 1,
};

struct ShipPlacement {
    int x, y;
    orientation orient;
    Ships type;
    ShipPlacement(int x_, int y_, orientation ori, Ships t) : x(x_), y(y_), orient(ori), type(t) {};
};

#endif
