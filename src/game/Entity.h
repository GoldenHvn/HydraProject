#ifndef HYDRA_ENTITY_H
#define HYDRA_ENTITY_H

#include <string>
#include "Vector3.h"

namespace hydra {

class Entity {
public:
    explicit Entity(std::string name) : m_name(std::move(name)) {}
    virtual ~Entity() = default;

    const std::string& getName() const { return m_name; }
    const Vector3& getPosition() const { return m_position; }
    void setPosition(const Vector3& pos) { m_position = pos; }

protected:
    std::string m_name;
    Vector3 m_position;
};

} // namespace hydra

#endif // HYDRA_ENTITY_H
