#include <lightray/raylib_application.h>
#include <lightray/raylib_window.h>
#include <lightray/drawing.h>

#include <raylib.h>

#include <print>

using namespace lightray;

class ExampleWindow : public lightray::RaylibWindow {
private:
public:
    ExampleWindow(int width, int height, std::string title) : RaylibWindow(width, height, title)
    {}

    static std::shared_ptr<ExampleWindow> create(int width, int height, std::string title)
    {
        return std::make_shared<ExampleWindow>(width, height, title);
    }

    virtual void onKeyPressed(int key) override
    {}

    virtual void onSetup() override
    {}

    virtual void onUpdate() override
    {}

    virtual void onDraw() override
    {
        background(RAYWHITE);
        circle(mouseX(), mouseY(), 50);
    }

    virtual void onResize(int width, int height) override
    {
        std::printf("window resized to %d x %d\n", width, height);
    }

    virtual void onMousePressed(lightray::MouseButton button, float x, float y) override
    {
        std::printf("mouse pressed at %f, %f\n", x, y);
    }

    virtual void onMouseMove(float x, float y) override
    {
        std::printf("mouse moved to %f, %f\n", x, y);
    }
};

typedef std::shared_ptr<DrawingWindow> DrawingWindowPtr;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int main(void)
{
    auto window = ExampleWindow::create(1024, 768, "lightray example");

    auto app = lightray::RaylibApplication::create(window);
    app->setConfigFlags(FLAG_MSAA_4X_HINT);
    app->setTargetFPS(60);
    app->loop();

    return 0;
}
