#include "Player.h"

namespace hydra {

Player::Player(const std::string& name)
    : Entity(name), m_level(1), m_experience(0) {}
int Player::getLevel() const { return m_level; }
int Player::getExperience() const { return m_experience; }

void Player::gainExperience(int amount) {
    m_experience += amount;
    while (m_experience >= m_level * 100) {
        m_experience -= m_level * 100;
        ++m_level;
    }
}

} // namespace hydra
