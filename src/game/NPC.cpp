#include "NPC.h"
#include "Player.h"

namespace hydra {

NPC::NPC(const std::string& name, int health)
    : Entity(name, health), m_moodValue(0) {}

Mood NPC::getMood() const {
    if (m_moodValue > 5) return Mood::Happy;
    if (m_moodValue < -5) return Mood::Angry;
    return Mood::Neutral;
}

void NPC::adjustMood(int delta) {
    m_moodValue += delta;
}

void NPC::attack(Player& target) {
    target.takeDamage(5);
}

} // namespace hydra
