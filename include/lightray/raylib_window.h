#pragma once

#include "raylib.h"
#include <string>
#include <memory>

namespace lightray {

enum class MouseButton {
    LEFT_BUTTON,
    RIGHT_BUTTON,
    MIDDLE_BUTTON,
    NO_BUTTON
};

class RaylibWindow {
private:
    int m_width{1024};
    int m_height{768};
    std::string m_title{"Raylib window"};

public:
    RaylibWindow(int width, int height, std::string title);

    static std::shared_ptr<RaylibWindow> create(int width, int height, std::string title);

    void setState(unsigned int flags);

    void setWidth(int width);
    void setHeight(int height);
    int width() const;
    int height() const;
    std::string title() const;

    float mouseX() const;
    float mouseY() const;

    MouseButton currentMouseButton() const;

    virtual void onInit();
    virtual void onSetup();
    virtual void onClear();
    virtual void onUpdate();
    virtual void onDraw();
    virtual void onResize(int width, int height);
    virtual void onKeyPressed(int key);
    virtual void onMousePressed(MouseButton button, float x, float y);
    virtual void onMouseMove(float x, float y);
    virtual void onClose();
};

typedef std::shared_ptr<RaylibWindow> RaylibWindowPtr;

} // namespace lightray
