#ifndef SOME_NEW_PROJECT_TEST_BOARD_H
#define SOME_NEW_PROJECT_TEST_BOARD_H

#include "doctest.h"
#include "../project/include/Board.h"

TEST_SUITE("testing Board class"){
    TEST_CASE("testing constructors with can_place_ship() method"){
        SUBCASE("no_args constructor"){
            Board board1;
            ShipPlacement sp;
            sp.x = 4, sp.y = 2, sp.orient = orientation::vertical, sp.type = Ships::small;
            CHECK_EQ(board1.can_place_ship(sp), true);
            sp.x = 0, sp.y = 0;
            CHECK_EQ(board1.can_place_ship(sp), false);
            sp.x = 7, sp.y = 0;
            CHECK_EQ(board1.can_place_ship(sp), false);
            sp.x = 0, sp.y = 7;
            CHECK_EQ(board1.can_place_ship(sp), false);
            sp.x = 11, sp.y = 7, sp.orient = orientation::horizontal;
            CHECK_EQ(board1.can_place_ship(sp), false);
            sp.x = 7, sp.y = 6, sp.orient = orientation::vertical;
            CHECK_EQ(board1.can_place_ship(sp), true);
            sp.x = 4, sp.y = 11;
            CHECK_EQ(board1.can_place_ship(sp), false);
            sp.x = 10, sp.y = 10, sp.orient = orientation::horizontal;
            CHECK_EQ(board1.can_place_ship(sp), true);
        }
        SUBCASE("const& constructor"){
            Board board1;
            ShipPlacement sp;
            sp.x = 4, sp.y = 2, sp.orient = orientation::vertical, sp.type = Ships::small;
            board1.place_ship(sp);
            Board board2(board1);
            CHECK_EQ(board2.is_alive(), true);
            CHECK_NE(board2.get_tile_status(4,2), Ships::water);
        }
    }
    TEST_CASE("testing is_alive() method"){
        Board board;
        ShipPlacement sp;
        sp.x = 4, sp.y = 2, sp.orient = orientation::vertical, sp.type = Ships::small;
        board.place_ship(sp);
        CHECK_EQ(board.is_alive(), true);
        board.get_shot(4,2,1);
        CHECK_EQ(board.is_alive(), false);
        sp.x = 6, sp.y = 2, sp.orient = orientation::horizontal, sp.type = Ships::carrier;
        board.place_ship(sp);
        CHECK_EQ(board.is_alive(), true);
        sp.x = 6, sp.y = 9, sp.type = Ships::small;
        board.place_ship(sp);
        CHECK_EQ(board.is_alive(), true);
        board.get_shot(6, 9, 1);
        CHECK_EQ(board.is_alive(), true);
    }
    TEST_CASE("testing operator="){
        Board board1;
        ShipPlacement sp;
        sp.x = 4, sp.y = 2, sp.orient = orientation::vertical, sp.type = Ships::small;
        board1.place_ship(sp);
        Board board2 = board1;
        CHECK_EQ(board2.is_alive(), board1.is_alive());
        CHECK_EQ(board2.get_tile_status(4,2), board1.get_tile_status(4,2));
    }
    TEST_CASE("testing can_shoot() method"){
        Board board1;
        CHECK_EQ(board1.can_shoot(0, 0, 1), false);
        CHECK_EQ(board1.can_shoot(2, 3, 1), true);
        CHECK_EQ(board1.can_shoot(4, 2, 1), true);
        CHECK_EQ(board1.can_shoot(2, 2, 1), true);
        CHECK_EQ(board1.can_shoot(11, 3, 1), false);
        CHECK_EQ(board1.can_shoot(4, 7, 1), true);
    }
    TEST_CASE("testing get_shot() method"){
        SUBCASE("small ship"){
            Board board1;
            ShipPlacement sp;
            sp.x = 5, sp.y = 6, sp.orient = orientation::vertical, sp.type = Ships::small;
            board1.place_ship(sp);
            CHECK_EQ(board1.is_alive(), true);
            board1.get_shot(5,6,1);
            CHECK_EQ(board1.is_alive(), false);
            CHECK_EQ(board1.get_tile_status(5,6), Ships::fire);
            CHECK_EQ(board1.can_shoot(5,6,1), false);
            CHECK_EQ(board1.can_shoot(5,7,1), false);
            CHECK_EQ(board1.can_shoot(5,5,1), false);
            CHECK_EQ(board1.can_shoot(4,6,1), false);
            CHECK_EQ(board1.can_shoot(6,6,1), false);
            CHECK_EQ(board1.can_shoot(4,5,1), false);
            CHECK_EQ(board1.can_shoot(6,7,1), false);
            CHECK_EQ(board1.can_shoot(6,5,1), false);
            CHECK_EQ(board1.can_shoot(4,7,1), false);
        }
        SUBCASE("other vertical"){
            Board board1;
            ShipPlacement sp;
            sp.x = 5, sp.y = 6, sp.orient = orientation::vertical, sp.type = Ships::middle;
            board1.place_ship(sp);
            CHECK_EQ(board1.is_alive(), true);
            board1.get_shot(5,6,1);
            CHECK_EQ(board1.is_alive(), true);
            CHECK_EQ(board1.get_tile_status(5,6), Ships::fire);
            CHECK_EQ(board1.can_shoot(5,6,1), false);
            CHECK_EQ(board1.can_shoot(5,7,1), true);
            CHECK_EQ(board1.can_shoot(5,5,1), true);
            CHECK_EQ(board1.can_shoot(4,6,1), true);
            CHECK_EQ(board1.can_shoot(6,6,1), true);
            CHECK_EQ(board1.can_shoot(4,5,1), true);
            CHECK_EQ(board1.can_shoot(6,7,1), true);
            CHECK_EQ(board1.can_shoot(6,5,1), true);
            CHECK_EQ(board1.can_shoot(4,7,1), true);
            board1.get_shot(6,6,1);
            CHECK_EQ(board1.is_alive(), false);
            CHECK_EQ(board1.can_shoot(5,6,1), false);
            CHECK_EQ(board1.can_shoot(5,7,1), false);
            CHECK_EQ(board1.can_shoot(5,5,1), false);
            CHECK_EQ(board1.can_shoot(4,6,1), false);
            CHECK_EQ(board1.can_shoot(6,6,1), false);
            CHECK_EQ(board1.can_shoot(4,5,1), false);
            CHECK_EQ(board1.can_shoot(6,7,1), false);
            CHECK_EQ(board1.can_shoot(6,5,1), false);
            CHECK_EQ(board1.can_shoot(4,7,1), false);
            CHECK_EQ(board1.can_shoot(7,6,1), false);
            CHECK_EQ(board1.can_shoot(7,5,1), false);
            CHECK_EQ(board1.can_shoot(7,7,1), false);
        }
        SUBCASE("other horizontal"){
            Board board1;
            ShipPlacement sp;
            sp.x = 5, sp.y = 6, sp.orient = orientation::horizontal, sp.type = Ships::middle;
            board1.place_ship(sp);
            CHECK_EQ(board1.is_alive(), true);
            board1.get_shot(5,6,1);
            CHECK_EQ(board1.is_alive(), true);
            CHECK_EQ(board1.get_tile_status(5,6), Ships::fire);
            CHECK_EQ(board1.can_shoot(5,6,1), false);
            CHECK_EQ(board1.can_shoot(5,7,1), true);
            CHECK_EQ(board1.can_shoot(5,5,1), true);
            CHECK_EQ(board1.can_shoot(4,6,1), true);
            CHECK_EQ(board1.can_shoot(6,6,1), true);
            CHECK_EQ(board1.can_shoot(4,5,1), true);
            CHECK_EQ(board1.can_shoot(6,7,1), true);
            CHECK_EQ(board1.can_shoot(6,5,1), true);
            CHECK_EQ(board1.can_shoot(4,7,1), true);
            board1.get_shot(5,7,1);
            CHECK_EQ(board1.is_alive(), false);
            CHECK_EQ(board1.get_tile_status(5,7), Ships::fire);
            CHECK_EQ(board1.can_shoot(5,7,1), false);
            CHECK_EQ(board1.can_shoot(6,7,1), false);
            CHECK_EQ(board1.can_shoot(4,7,1), false);
            CHECK_EQ(board1.can_shoot(5,6,1), false);
            CHECK_EQ(board1.can_shoot(5,8,1), false);
            CHECK_EQ(board1.can_shoot(4,6,1), false);
            CHECK_EQ(board1.can_shoot(4,8,1), false);
            CHECK_EQ(board1.can_shoot(6,6,1), false);
            CHECK_EQ(board1.can_shoot(6,8,1), false);
            CHECK_EQ(board1.can_shoot(5,5,1), false);
            CHECK_EQ(board1.can_shoot(4,5,1), false);
            CHECK_EQ(board1.can_shoot(6,5,1), false);
        }
    }
    TEST_CASE("testing is_visible() method"){
        Board board1;
        board1.get_shot(1, 5, 1);
        CHECK_EQ(board1.is_visible(1,5,1), true);
        CHECK_EQ(board1.is_visible(1,4,1), false);
    }
    TEST_CASE("testing get_tile_status() method"){
        Board board1;
        ShipPlacement sp;
        sp.x = 5, sp.y = 6, sp.orient = orientation::horizontal, sp.type = Ships::middle;
        board1.place_ship(sp);
        CHECK_EQ(board1.get_tile_status(5,6), Ships::middle);
        CHECK_EQ(board1.get_tile_status(5,7), Ships::middle);
        CHECK_EQ(board1.get_tile_status(6,8), Ships::water);
    }
    TEST_CASE("testing can_place_ship() method"){
        Board board1;
        ShipPlacement sp;
        sp.x = 0, sp.y = 6, sp.orient = orientation::horizontal, sp.type = Ships::middle;
        CHECK_EQ(board1.can_place_ship(sp), false);
        sp.x = 5;
        board1.place_ship(sp);
        sp.x = 6;
        CHECK_EQ(board1.can_place_ship(sp), false);
        sp.y = 5;
        sp.orient = orientation::vertical;
        CHECK_EQ(board1.can_place_ship(sp), false);
        sp.x = 4;
        CHECK_EQ(board1.can_place_ship(sp), false);
        sp.y = 8;
        CHECK_EQ(board1.can_place_ship(sp), false);
        sp.x = 6;
        CHECK_EQ(board1.can_place_ship(sp), false);
        sp.x = 10;
        sp.y = 10;
        sp.orient = orientation::vertical;
        sp.type = Ships::small;
        CHECK_EQ(board1.can_place_ship(sp), true);
        sp.orient = orientation::horizontal;
        CHECK_EQ(board1.can_place_ship(sp), true);
    }
    TEST_CASE("testing place_ship() method"){
        Board board1;
        ShipPlacement sp;
        sp.x = 1, sp.y = 6, sp.orient = orientation::horizontal, sp.type = Ships::middle;
        board1.place_ship(sp);
        CHECK_EQ(board1.get_tile_status(1,1), Ships::middle);
        CHECK_EQ(board1.get_tile_status(1,2), Ships::middle);
        sp.x = 10;
        sp.y = 10;
        sp.orient = orientation::vertical;
        sp.type = Ships::small;
        board1.place_ship(sp);
        CHECK_EQ(board1.get_tile_status(10, 10), Ships::small);
    }
}

#endif //SOME_NEW_PROJECT_TEST_BOARD_H
