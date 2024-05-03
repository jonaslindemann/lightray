#include <lightray/shape.h>

#include <raylib.h>

namespace lightray {

DrawingState *DrawingState::m_instance = nullptr;

void DrawingState::stroke(Color color)
{
    m_drawStroke = true;
    m_strokeColor = color;
}

Color DrawingState::stroke() const
{
    return m_strokeColor;
}

void DrawingState::strokeWeight(float weight)
{
    m_strokeWidth = weight;
}

float DrawingState::strokeWeight() const
{
    return m_strokeWidth;
}

void DrawingState::fill(Color color)
{
    m_fillColor = color;
    m_drawFill = true;
}

Color DrawingState::fill() const
{
    return m_fillColor;
}

void DrawingState::ellipseMode(EllipseMode mode)
{}

EllipseMode DrawingState::ellipseMode()
{
    return EllipseMode();
}

void DrawingState::noStroke()
{
    m_drawStroke = false;
}

void DrawingState::noFill()
{
    m_drawFill = false;
}

bool DrawingState::drawStroke() const
{
    return m_drawStroke;
}

bool DrawingState::drawFill() const
{
    return m_drawFill;
}

void DrawingState::alpha(unsigned char alpha)
{
    m_strokeColor.a = alpha;
    m_fillColor.a = alpha;
}

unsigned char DrawingState::alpha() const
{
    return m_fillColor.a;
}

void arc(float a, float b, float c, float d, float start, float stop)
{
    // DrawArc(Vector2{a, b}, c, d, start, stop, 10, RED);
}

void circle(float x, float y, float extent)
{
    if (ellipseMode() == EllipseMode::CORNER)
        x += extent / 2, y += extent / 2;

    if (drawFill())
        DrawCircle(x, y, extent, fill());

    float r1 = extent - strokeWeight() / 2;
    float r2 = extent + strokeWeight() / 2;

    if (drawStroke())
        for (float r = r1; r < r2; r += 0.5f)
            DrawCircleLines(x, y, r, stroke());
}

void ellipse(float x, float y, float a, float b)
{
    DrawEllipse(x, y, a, b, RED);
}

void line(float x1, float y1, float x2, float y2)
{
    DrawLine(x1, y1, x2, y2, RED);
}

void point(float x, float y)
{
    DrawPixel(x, y, RED);
}

void rect(float x, float y, float w, float h)
{
    DrawRectangle(x, y, w, h, RED);
}

void square(float x, float y, float extent)
{
    DrawRectangle(x, y, extent, extent, RED);
}

void triangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    DrawTriangle(Vector2{x1, y1}, Vector2{x2, y2}, Vector2{x3, y3}, RED);
}

void quad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    DrawRectangle(x1, y1, x2 - x1, y3 - y1, RED);
}

static EllipseMode ellipseMode()
{
    return DrawingState::instance()->ellipseMode();
}

static void ellipseMode(EllipseMode mode)
{
    DrawingState::instance()->ellipseMode(mode);
}

void noStroke()
{
    DrawingState::instance()->noStroke();
}

void noFill()
{
    DrawingState::instance()->noFill();
}

bool drawStroke()
{
    return DrawingState::instance()->drawStroke();
}

bool drawFill()
{
    return DrawingState::instance()->drawFill();
}

void stroke(Color color)
{
    DrawingState::instance()->stroke(color);
}

Color stroke()
{
    return DrawingState::instance()->stroke();
}

void strokeWeight(float weight)
{
    DrawingState::instance()->strokeWeight(weight);
}

float strokeWeight()
{
    return DrawingState::instance()->strokeWeight();
}

void fill(Color color)
{
    DrawingState::instance()->fill(color);
}

Color fill()
{
    return DrawingState::instance()->fill();
}

}; // namespace lightray
