#ifndef HYDRA_LOADINGSCREEN_H
#define HYDRA_LOADINGSCREEN_H

#include <iostream>

namespace hydra {

class LoadingScreen {
public:
    void show();
    void setProgress(int percent);
    void hide();

private:
    int m_progress = 0;
    bool m_visible = false;
};

} // namespace hydra

#endif // HYDRA_LOADINGSCREEN_H
