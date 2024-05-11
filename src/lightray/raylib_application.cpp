#include "lightray/raylib_application.h"

using namespace lightray;

RaylibApplication::RaylibApplication(RaylibWindowPtr window)
    : m_window(window), m_mousePos({0, 0}), m_lastMousePos({0, 0})
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

    m_mousePos = GetMousePosition();
    m_lastMousePos = m_mousePos;

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        if (IsWindowResized())
        {
            m_window->setWidth(GetRenderWidth());
            m_window->setHeight(GetRenderHeight());
            m_window->onResize(m_window->width(), m_window->height());
        }

        // Check keyboard

        auto keycode = GetKeyPressed();

        while (keycode != 0)
        {
            m_window->onKeyPressed(keycode);
            keycode = GetKeyPressed();
        }

        // Check mouse

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            auto mousePos = GetMousePosition();
            m_window->onMousePressed(MouseButton::LEFT_BUTTON, mousePos.x, mousePos.y);
        }
        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
        {
            auto mousePos = GetMousePosition();
            m_window->onMousePressed(MouseButton::RIGHT_BUTTON, mousePos.x, mousePos.y);
        }
        if (IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON))
        {
            auto mousePos = GetMousePosition();
            m_window->onMousePressed(MouseButton::MIDDLE_BUTTON, mousePos.x, mousePos.y);
        }

        // Check mouse move

        m_mousePos = GetMousePosition();

        if (m_mousePos.x != m_lastMousePos.x || m_mousePos.y != m_lastMousePos.y)
            m_window->onMouseMove(m_mousePos.x, m_mousePos.y);

        m_lastMousePos = m_mousePos;

        // Update and draw

        m_window->onUpdate();
        m_window->onClear();
        BeginDrawing();
        m_window->onDraw();
        EndDrawing();
    }

    m_window->onClose();

    CloseWindow();
}
