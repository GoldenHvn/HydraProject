#ifndef HYDRA_GAMESTATE_H
#define HYDRA_GAMESTATE_H

#include "NPC.h"
#include "Quest.h"
#include <vector>

namespace hydra {

class GameState {
public:
    void addNPC(const NPC& npc);
    NPC* findNPC(const std::string& name);

    void addQuest(const Quest& quest);
    Quest* getCurrentQuest();

    void travelToFuture();
    void travelToPast();

private:
    std::vector<NPC> m_npcs;
    std::vector<Quest> m_quests;
    size_t m_activeQuest = 0;
    int m_timeIndex = 0; // simple representation of timeline
};

} // namespace hydra

#endif // HYDRA_GAMESTATE_H
