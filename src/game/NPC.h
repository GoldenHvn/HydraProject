#ifndef HYDRA_NPC_H
#define HYDRA_NPC_H

#include <string>
#include "Entity.h"

namespace hydra {

class Player; // forward declaration
enum class Mood {
    Neutral,
    Happy,
    Angry
};

class NPC : public Entity {
public:
    NPC(const std::string& name, int health = 100);

    Mood getMood() const;

    void adjustMood(int delta);
    void attack(Player& target);

private:
    int m_moodValue; // simple mood scale
};

} // namespace hydra

#endif // HYDRA_NPC_H
