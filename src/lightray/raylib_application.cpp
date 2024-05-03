#include "lightray/raylib_application.h"

using namespace lightray;

RaylibApplication::RaylibApplication(RaylibWindowPtr window) : m_window(window)
{}

std::unique_ptr<RaylibApplication> lightray::RaylibApplication::create(RaylibWindowPtr window)
{
    return std::make_unique<RaylibApplication>(window);
}

void lightray::RaylibApplication::setWindow(RaylibWindowPtr window)
{
    m_window = window;
}

void lightray::RaylibApplication::setConfigFlags(unsigned int flags)
{
    SetConfigFlags(flags);
}

void lightray::RaylibApplication::setTargetFPS(int fps)
{
    SetTargetFPS(fps);
}

void RaylibApplication::loop()
{
    if (m_window == nullptr)
        return;

    m_window->onInit();
    m_window->onSetup();

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        if (IsWindowResized())
            m_window->onResize(GetRenderWidth(), GetRenderHeight());

        // Check keyboard

        auto keycode = GetKeyPressed();

        while (keycode != 0)
        {
			m_window->onKeyPressed(keycode);
			keycode = GetKeyPressed();
		}

        m_window->onUpdate();
        m_window->onClear();
        BeginDrawing();
        m_window->onDraw();
        EndDrawing();
    }

    CloseWindow();
}
