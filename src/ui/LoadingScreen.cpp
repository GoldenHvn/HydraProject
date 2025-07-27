#include "LoadingScreen.h"
#include <thread>
#include <chrono>

namespace hydra {

void LoadingScreen::show() {
    m_visible = true;
    setProgress(0);
}

void LoadingScreen::setProgress(int percent) {
    m_progress = percent;
    if (m_visible) {
        std::cout << "\rLoading: " << m_progress << "%" << std::flush;
    }
}

void LoadingScreen::hide() {
    if (m_visible) {
        std::cout << std::endl;
    }
    m_visible = false;
}

} // namespace hydra
