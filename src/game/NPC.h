#ifndef HYDRA_NPC_H
#define HYDRA_NPC_H

#include <string>
#include "Entity.h"

namespace hydra {

enum class Mood {
    Neutral,
    Happy,
    Angry
};

class NPC : public Entity {
public:
    NPC(const std::string& name);

    Mood getMood() const;

    void adjustMood(int delta);

private:
    int m_moodValue; // simple mood scale
};

} // namespace hydra

#endif // HYDRA_NPC_H
