#pragma once

#include "raylib.h"
#include <string>
#include <memory>

namespace lightray {

class RaylibWindow {
private:
    int m_width{1024};
    int m_height{768};
    std::string m_title{"Raylib window"};

public:
    RaylibWindow(int width, int height, std::string title);

    static std::shared_ptr<RaylibWindow> create(int width, int height, std::string title);

    void setState(unsigned int flags);

    int width() const;
    int height() const;
    std::string title() const;

    virtual void onInit();
    virtual void onSetup();
    virtual void onClear();
    virtual void onUpdate();
    virtual void onDraw();
};

typedef std::shared_ptr<RaylibWindow> RaylibWindowPtr;

} // namespace lightray
