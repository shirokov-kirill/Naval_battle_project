
#ifndef UNTITLED_TEST_SHIPPLACEMENT_H
#define UNTITLED_TEST_SHIPPLACEMENT_H

#include "../project/include/ShipPlacement.h"
#include "doctest.h"

TEST_SUITE("testing ShipPlacement class"){
    TEST_CASE("testing constructor"){
        ShipPlacement sp(3, 5, orientation::vertical, Ships::carrier);
        CHECK_EQ(sp.type, Ships::carrier);
        CHECK_EQ(sp.orient, orientation::vertical);
    }
};

#endif //UNTITLED_TEST_SHIPPLACEMENT_H
