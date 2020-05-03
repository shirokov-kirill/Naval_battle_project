#ifndef BOT_H
#define BOT_H

#include"../include/Player.h"

class Bot : public Player {
public:
    Bot() {current_ship_taget = {0, 0};} ;
    virtual ~Bot();
    virtual bool is_bot() const noexcept override;
    pair<int, int> make_fight_step(Player* other_player);
    void make_placement();
private:
    pair<int, int> int current_ship_taget;
};


#endif // BOT_H