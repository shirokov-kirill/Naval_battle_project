#ifndef BOT_H
#define BOT_H

#include"../include/Player.h"

#include <utility>

class Bot : public Player {
public:
    Bot() {
        current_ship_target = {0, 0};
        target_orientation = orientation::undefined;
    }
    virtual ~Bot() = default;
    virtual bool is_bot() const noexcept override;
    std::pair<std::size_t, std::size_t> make_fight_step(Player* other_player);
    void make_placement();
private:
    std::pair<std::size_t, std::size_t> current_ship_target;
    orientation target_orientation;
};


#endif // BOT_H
