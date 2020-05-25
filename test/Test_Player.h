#ifndef UNTITLED_TEST_PLAYER_H
#define UNTITLED_TEST_PLAYER_H

#include "doctest.h"
#include "../project/include/Player.h"

TEST_SUITE("testing Player class"){
    TEST_CASE("testing constructor"){
        Player player1;
        CHECK_EQ(player1.get_score(), 0);
        CHECK_EQ(player1.get_cur_ship(), 0);
    }
    TEST_CASE("testing increase_score() method"){
        Player player1;
        player1.increase_score(243);
        CHECK_EQ(player1.get_score(), 243);
        player1.increase_score(2);
        CHECK_EQ(player1.get_score(), 245);
    }
    TEST_CASE("testing get_shot() and is_visible() methods"){
        Player player1;
        player1.get_shot(0, 0, 1);
        CHECK_EQ(player1.is_visible(0, 0, 1), true);
        CHECK_EQ(player1.is_visible(1, 0, 1), false);
    }
    TEST_CASE("testing set_name() method"){
        Player player1;
        player1.set_name("gfljgdlWDFDxcxv3");
        CHECK_NE(player1.get_name(), "");
        CHECK_EQ(player1.get_name(), "gfljgdlWDFDxcxv3");
    }
    TEST_CASE("testing place_ship()"){
        SUBCASE("horizontal"){
            Player player1;
            ShipPlacement sp(4, 2, orientation::horizontal, Ships::middle);
            player1.place_ship(sp);
            CHECK_EQ(player1.is_alive(), true);
            CHECK_EQ(player1.get_cur_ship(), 1);
            CHECK_EQ(player1.get_cell(4,2), Ships::middle);
            CHECK_EQ(player1.get_cell(5,2), Ships::middle);
            CHECK_NE(player1.get_cell(6,2), Ships::middle);
            CHECK_NE(player1.get_cell(3,2), Ships::middle);
        }
        SUBCASE("vertical"){
            Player player1;
            ShipPlacement sp(4, 2, orientation::vertical, Ships::middle);
            player1.place_ship(sp);
            CHECK_EQ(player1.is_alive(), true);
            CHECK_EQ(player1.get_cur_ship(), 1);
            CHECK_EQ(player1.get_cell(4,2), Ships::middle);
            CHECK_EQ(player1.get_cell(4,3), Ships::middle);
            CHECK_NE(player1.get_cell(4,4), Ships::middle);
            CHECK_NE(player1.get_cell(4,1), Ships::middle);
        }
    }
    TEST_CASE("testing is_alive() method"){
        SUBCASE("alive"){
            Player player1;
            ShipPlacement sp(4, 2, orientation::vertical, Ships::middle);
            player1.place_ship(sp);
            CHECK_EQ(player1.is_alive(), true);
            CHECK_EQ(player1.get_cur_ship(), 1);
        }
        SUBCASE("not alive"){
            Player player1;
            ShipPlacement sp(4, 2, orientation::vertical, Ships::small);
            player1.get_shot(4, 2, 1);
            CHECK_EQ(player1.is_alive(), false);
            CHECK_EQ(player1.get_cur_ship(), 0);
        }
    }
    TEST_CASE("testing can_shoot() method"){
        Player player;
        player.get_shot(4,5,1);
        CHECK_EQ(player.can_shoot(3,1,1), true);
        CHECK_EQ(player.can_shoot(4,5,1), false);
    }
    TEST_CASE("testing operator = method"){
        Player player1;
        ShipPlacement sp(4, 2, orientation::vertical, Ships::small);
        Player player2;
        player2.increase_score(345);
        player2.set_name("flgkflgkdf3;");
        player2.place_ship(sp);
        player2.get_shot(1, 0, 1);
        player1 = player2;
        CHECK_EQ(player1.get_score(), 345);
        CHECK_EQ(player1.get_name(), "flgkflgkdf3;");
        CHECK_EQ(player1.is_visible(1, 0, 1), true);
        CHECK_EQ(player1.is_visible(2,3,1), false);
        CHECK_EQ(player1.get_cur_ship(), 1);
    }
    TEST_CASE("testing inc_ship() method"){
        Player player1;
        player1.inc_ship();
        CHECK_EQ(player1.get_cur_ship(), 1);
        player1.inc_ship();
        CHECK_EQ(player1.get_cur_ship(), 2);
    }
}

#endif //UNTITLED_TEST_PLAYER_H
