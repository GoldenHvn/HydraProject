#include "NPC.h"

namespace hydra {

NPC::NPC(const std::string& name)
    : Entity(name), m_moodValue(0) {}

Mood NPC::getMood() const {
    if (m_moodValue > 5) return Mood::Happy;
    if (m_moodValue < -5) return Mood::Angry;
    return Mood::Neutral;
}

void NPC::adjustMood(int delta) {
    m_moodValue += delta;
}

} // namespace hydra
