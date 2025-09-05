#ifndef HYDRA_ENTITY_H
#define HYDRA_ENTITY_H

#include <string>
#include <algorithm>
#include "Vector3.h"

namespace hydra {

class Entity {
public:
    explicit Entity(std::string name, int health = 100)
        : m_name(std::move(name)), m_health(health) {}
    virtual ~Entity() = default;

    const std::string& getName() const { return m_name; }
    const Vector3& getPosition() const { return m_position; }
    void setPosition(const Vector3& pos) { m_position = pos; }

    int getHealth() const { return m_health; }
    bool isAlive() const { return m_health > 0; }
    void takeDamage(int amount) { m_health = std::max(0, m_health - amount); }
    void heal(int amount) { m_health += amount; }

protected:
    std::string m_name;
    Vector3 m_position;
    int m_health;
};

} // namespace hydra

#endif // HYDRA_ENTITY_H
