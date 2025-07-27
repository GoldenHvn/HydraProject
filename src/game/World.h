#ifndef HYDRA_WORLD_H
#define HYDRA_WORLD_H

#include "Player.h"
#include "NPC.h"
#include <vector>

namespace hydra {

class World {
public:
    void addPlayer(const Player& player);
    void update();

private:
    std::vector<Player> m_players;
};

} // namespace hydra

#endif // HYDRA_WORLD_H
