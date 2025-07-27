#include "GameState.h"

namespace hydra {

void GameState::addNPC(const NPC& npc) { m_npcs.push_back(npc); }

NPC* GameState::findNPC(const std::string& name) {
    for (auto& n : m_npcs) {
        if (n.getName() == name) return &n;
    }
    return nullptr;
}

void GameState::addQuest(const Quest& quest) { m_quests.push_back(quest); }

Quest* GameState::getCurrentQuest() {
    if (m_activeQuest < m_quests.size())
        return &m_quests[m_activeQuest];
    return nullptr;
}

void GameState::travelToFuture() { ++m_timeIndex; }

void GameState::travelToPast() { if (m_timeIndex > 0) --m_timeIndex; }

} // namespace hydra
