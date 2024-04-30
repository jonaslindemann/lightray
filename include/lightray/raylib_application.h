#pragma once

#include "raylib.h"
#include "raylib_window.h"

namespace lightray {

class RaylibApplication {
private:
    RaylibWindowPtr m_window;

public:
    RaylibApplication(RaylibWindowPtr window);

    static std::unique_ptr<RaylibApplication> create(RaylibWindowPtr window);

    void setWindow(RaylibWindowPtr window);
    void setConfigFlags(unsigned int flags);
    void setTargetFPS(int fps);

    void loop();
};

typedef std::unique_ptr<RaylibApplication> RaylibApplicationPtr;

} // namespace lightray
