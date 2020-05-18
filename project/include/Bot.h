#ifndef BOT_H
#define BOT_H

#include"../include/Player.h"

#include <utility>

class Bot : public Player {
public:
    Bot() {current_ship_target = {0, 0};} ;
    virtual ~Bot();
    virtual bool is_bot() const noexcept override;
    std::pair<int, int> make_fight_step(Player* other_player);
    void make_placement();
private:
    std::pair<int, int> current_ship_target;
};


#endif // BOT_H
