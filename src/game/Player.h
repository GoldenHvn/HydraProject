#ifndef HYDRA_PLAYER_H
#define HYDRA_PLAYER_H

#include <string>
#include "Entity.h"

namespace hydra {

class Player : public Entity {
public:
    Player(const std::string& name);

    int getLevel() const;
    int getExperience() const;

    void gainExperience(int amount);

private:
    int m_level;
    int m_experience;
};

} // namespace hydra

#endif // HYDRA_PLAYER_H
