#include "pch.h"
#include "Player.h"
#include "gtest/gtest.h"

class PlayerTest : public ::testing::Test{
protected:
    void SetUp() override {
        _player = new Player;
    }
    void TearDown() override {
        delete _player;
    }
    Player *_player;
};

TEST_F(PlayerTest, TestIncreaseScore){
    ASSERT_EQ(_player->get_score(), 0);
    _player->increase_score(7);
    ASSERT_EQ(_player->get_score(), 7);
    int num = 4;
    _player->increase_score(num);
    ASSERT_EQ(_player->get_score(), 11);
}

TEST_F(PlayerTest, TestSetName) {
    ASSERT_EQ(_player->get_name(), "");
    _player->set_name("Bob");
    ASSERT_EQ(_player->get_name(), "Bob");
    _player->set_name("");
    ASSERT_EQ(_player->get_name(), "");
    std::string s = "Bred";
    _player->set_name(s);
    ASSERT_EQ(_player->get_name(), "Bred");
}

TEST_F(PlayerTest, TestOperatorEq) {
    Player player;
    player.set_name("Bob");
    player.increase_score(149);
    player.get_shot(0, 0, 0);
    *_player = player;
    ASSERT_EQ(_player->get_name(), "Bob");
    ASSERT_EQ(_player->get_score(), 149);
}

int main() {
    return RUN_ALL_TESTS();
}