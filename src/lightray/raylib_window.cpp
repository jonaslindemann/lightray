#include "lightray/raylib_window.h"

using namespace lightray;

RaylibWindow::RaylibWindow(int width, int height, std::string title) : m_width(width), m_height(height), m_title(title)
{}

void lightray::RaylibWindow::setState(unsigned int flags)
{
    SetWindowState(flags);
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

void lightray::RaylibWindow::onInit()
{
    InitWindow(m_width, m_height, m_title.c_str());
    SetWindowState(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
}

void lightray::RaylibWindow::onSetup()
{}

void lightray::RaylibWindow::onClear()
{
    ClearBackground(RAYWHITE);
}

void lightray::RaylibWindow::onUpdate()
{}

void lightray::RaylibWindow::onDraw()
{}
