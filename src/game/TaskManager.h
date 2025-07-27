#ifndef HYDRA_TASKMANAGER_H
#define HYDRA_TASKMANAGER_H

#include <functional>
#include <thread>
#include <vector>

namespace hydra {

class TaskManager {
public:
    TaskManager() = default;
    ~TaskManager();

    void startTask(std::function<void()> func);

private:
    std::vector<std::thread> m_threads;
};

} // namespace hydra

#endif // HYDRA_TASKMANAGER_H
