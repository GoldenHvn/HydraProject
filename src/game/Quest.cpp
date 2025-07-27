#include "Quest.h"

namespace hydra {

Quest::Quest(const std::string& name, QuestType type)
    : m_name(name), m_type(type) {}

const std::string& Quest::getName() const { return m_name; }
QuestType Quest::getType() const { return m_type; }

bool Quest::isCompleted() const { return m_completed; }

void Quest::complete() { m_completed = true; }

} // namespace hydra
