#include "TaskManager.h"

namespace hydra {

TaskManager::~TaskManager() {
    for (auto& t : m_threads) {
        if (t.joinable()) t.join();
    }
}

void TaskManager::startTask(std::function<void()> func) {
    m_threads.emplace_back(std::move(func));
}

} // namespace hydra
