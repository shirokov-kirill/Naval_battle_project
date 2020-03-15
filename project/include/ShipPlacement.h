#ifndef NAVAL_BATTLE_SHIP_PLACEMENT_H
#define NAVAL_BATTLE_SHIP_PLACEMENT_H

enum class Ships {
    fire = -1,
    water = 0,
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
};

#endif
