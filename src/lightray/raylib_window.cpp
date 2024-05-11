#include "lightray/raylib_window.h"

using namespace lightray;

RaylibWindow::RaylibWindow(int width, int height, std::string title) : m_width(width), m_height(height), m_title(title)
{}

void lightray::RaylibWindow::setState(unsigned int flags)
{
    SetWindowState(flags);
}

void lightray::RaylibWindow::setWidth(int width)
{
    m_width = width;
}

void lightray::RaylibWindow::setHeight(int height)
{
    m_height = height;
}

int lightray::RaylibWindow::width() const
{
    return m_width;
}

int lightray::RaylibWindow::height() const
{
    return m_height;
}

std::string lightray::RaylibWindow::title() const
{
    return m_title;
}

float lightray::RaylibWindow::mouseX() const
{
    auto pos = GetMousePosition();
    return pos.x;
}

float lightray::RaylibWindow::mouseY() const
{
    auto pos = GetMousePosition();
    return pos.y;
}

lightray::MouseButton lightray::RaylibWindow::currentMouseButton() const
{
    MouseButton button = MouseButton::NO_BUTTON;

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        button = MouseButton::LEFT_BUTTON;
    else if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
        button = MouseButton::RIGHT_BUTTON;
    else if (IsMouseButtonDown(MOUSE_MIDDLE_BUTTON))
        button = MouseButton::MIDDLE_BUTTON;

    return button;
}

void lightray::RaylibWindow::onInit()
{
    InitWindow(m_width, m_height, m_title.c_str());
    SetWindowState(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
}

void lightray::RaylibWindow::onSetup()
{}

void lightray::RaylibWindow::onClear()
{}

void lightray::RaylibWindow::onUpdate()
{}

void lightray::RaylibWindow::onDraw()
{}

void lightray::RaylibWindow::onResize(int width, int height)
{}

void lightray::RaylibWindow::onKeyPressed(int key)
{}

void lightray::RaylibWindow::onMousePressed(MouseButton button, float x, float y)
{}

void lightray::RaylibWindow::onMouseMove(float x, float y)
{}

void lightray::RaylibWindow::onClose()
{}
