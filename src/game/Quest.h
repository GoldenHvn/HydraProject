#ifndef HYDRA_QUEST_H
#define HYDRA_QUEST_H

#include <string>

namespace hydra {

enum class QuestType {
    None,
    TimeTravel,
    Rescue,
    Hunt
};

class Quest {
public:
    Quest(const std::string& name, QuestType type);

    const std::string& getName() const;
    QuestType getType() const;
    bool isCompleted() const;
    void complete();

private:
    std::string m_name;
    QuestType m_type;
    bool m_completed{false};
};

} // namespace hydra

#endif // HYDRA_QUEST_H
