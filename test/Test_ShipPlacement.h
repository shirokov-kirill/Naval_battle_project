
#ifndef UNTITLED_TEST_SHIPPLACEMENT_H
#define UNTITLED_TEST_SHIPPLACEMENT_H

#include "../project/include/ShipPlacement.h"
#include "doctest.h"

TEST_SUITE("testing ShipPlacement class"){
    TEST_CASE("testing constructor"){
        auto shipPlacement = new ShipPlacement();
        shipPlacement->x = 3;
        shipPlacement->y = 5;
        shipPlacement->type = Ships::carrier;
        shipPlacement->orient = orientation::vertical;
        CHECK_EQ((int)shipPlacement->type, 4);
        CHECK_EQ((int)shipPlacement->orient, 1);
    }
};

#endif //UNTITLED_TEST_SHIPPLACEMENT_H
