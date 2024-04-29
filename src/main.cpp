/*******************************************************************************************
 *
 *   raylib [shapes] example - Draw basic shapes 2d (rectangle, circle, line...)
 *
 *   Example originally created with raylib 1.0, last time updated with raylib 4.2
 *
 *   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
 *   BSD-like license that allows static linking with closed source software
 *
 *   Copyright (c) 2014-2024 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include "raylib_application.h"
#include "raylib_window.h"
#include "raylib.h"

class DrawingWindow : public lightray::RaylibWindow {
private:
    float m_rotation{0.0f};

public:
    DrawingWindow(int width, int height, std::string title) : RaylibWindow(width, height, title)
    {}

    static std::shared_ptr<DrawingWindow> create(int width, int height, std::string title)
    {
        return std::make_shared<DrawingWindow>(width, height, title);
    }

    virtual void onSetup() override
    {}

    virtual void onUpdate() override
    {
        m_rotation += 0.2f;
    }

    virtual void onDraw() override
    {
        DrawText("some basic shapes available on raylib", 20, 20, 20, DARKGRAY);

        // Circle shapes and lines
        DrawCircle(this->width() / 5, 120, 35, DARKBLUE);
        DrawCircleGradient(this->width() / 5, 220, 60, GREEN, SKYBLUE);
        DrawCircleLines(this->width() / 5, 340, 80, DARKBLUE);

        // Rectangle shapes and lines
        DrawRectangle(this->width() / 4 * 2 - 60, 100, 120, 60, RED);
        DrawRectangleGradientH(this->width() / 4 * 2 - 90, 170, 180, 130, MAROON, GOLD);
        DrawRectangleLines(this->width() / 4 * 2 - 40, 320, 80, 60, ORANGE); // NOTE: Uses QUADS internally, not lines

        // Triangle shapes and lines
        DrawTriangle(Vector2{this->width() / 4.0f * 3.0f, 80.0f}, Vector2{this->width() / 4.0f * 3.0f - 60.0f, 150.0f},
                     Vector2{this->width() / 4.0f * 3.0f + 60.0f, 150.0f}, VIOLET);

        DrawTriangleLines(Vector2{this->width() / 4.0f * 3.0f, 160.0f},
                          Vector2{this->width() / 4.0f * 3.0f - 20.0f, 230.0f},
                          Vector2{this->width() / 4.0f * 3.0f + 20.0f, 230.0f}, DARKBLUE);

        // Polygon shapes and lines
        DrawPoly(Vector2{this->width() / 4.0f * 3, 330}, 6, 80, m_rotation, BROWN);
        DrawPolyLines(Vector2{this->width() / 4.0f * 3, 330}, 6, 90, m_rotation, BROWN);
        DrawPolyLinesEx(Vector2{this->width() / 4.0f * 3, 330}, 6, 85, m_rotation, 6, BEIGE);

        // NOTE: We draw all LINES based shapes together to optimize internal drawing,
        // this way, all LINES are rendered in a single draw pass
        DrawLine(18, 42, this->width() - 18, 42, BLACK);
    }
};

typedef std::shared_ptr<DrawingWindow> DrawingWindowPtr;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    auto window = DrawingWindow::create(1024, 768, "lightray example");

    auto app = lightray::RaylibApplication::create(window);
    app->setConfigFlags(FLAG_MSAA_4X_HINT);
    app->setTargetFPS(60);
    app->loop();

    return 0;
}
