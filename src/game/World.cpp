#include "World.h"

namespace hydra {

void World::addPlayer(const Player& player) { m_players.push_back(player); }

void World::update() {
    // Placeholder for world update logic
    for (auto& p : m_players) {
        p.gainExperience(1); // simple tick exp
        if (p.isAlive())
            p.takeDamage(1); // environmental damage example
    }
}

} // namespace hydra
