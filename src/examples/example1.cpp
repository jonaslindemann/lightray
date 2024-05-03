#include <lightray/raylib_application.h>
#include <lightray/raylib_window.h>
#include <lightray/shape.h>

#include <raylib.h>

using namespace lightray;

enum class DrawShapes {
	CIRCLE,
	RECTANGLE
};

class DrawingWindow : public lightray::RaylibWindow {
private:
    float m_rotation{0.0f};
    DrawShapes m_drawShapes{DrawShapes::CIRCLE};
    RectMode m_rectMode{RectMode::CORNER};
    EllipseMode m_ellipseMode{EllipseMode::CENTER};

public:
    DrawingWindow(int width, int height, std::string title) : RaylibWindow(width, height, title)
    {}

    static std::shared_ptr<DrawingWindow> create(int width, int height, std::string title)
    {
        return std::make_shared<DrawingWindow>(width, height, title);
    }

    virtual void onKeyPressed(int key) override
    {
		if (key == KEY_C)
			m_drawShapes = DrawShapes::CIRCLE;
		else if (key == KEY_R)
			m_drawShapes = DrawShapes::RECTANGLE;
        else if (key == KEY_ONE)
			m_rectMode = RectMode::CORNER;
		else if (key == KEY_TWO)
			m_rectMode = RectMode::CORNERS;
		else if (key == KEY_THREE)
			m_rectMode = RectMode::CENTER;
		else if (key == KEY_FOUR)
			m_rectMode = RectMode::RADIUS;
		else if (key == KEY_FIVE)
			m_ellipseMode = EllipseMode::CENTER;
		else if (key == KEY_SIX)
			m_ellipseMode = EllipseMode::RADIUS;
		else if (key == KEY_SEVEN)
			m_ellipseMode = EllipseMode::CORNER;

        rectMode(m_rectMode);
        ellipseMode(m_ellipseMode);
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

        if (m_drawShapes == DrawShapes::CIRCLE)
        {
            circle(224, 184, 220);
            circle(224, 184, 5);
        }
        else if (m_drawShapes == DrawShapes::RECTANGLE)
        {
            rect(120, 80, 220, 220);
            circle(120, 80, 5);
            rect(120 + 300, 80, 220, 220, 28);
            circle(120 + 300, 80, 5);
        }


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
