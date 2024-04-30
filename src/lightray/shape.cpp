#include <lightray/shape.h>

#include <raylib.h>

namespace lightray {

DrawingState *DrawingState::m_instance = nullptr;


void DrawingState::stroke(Color color)
{
    m_strokeColor = color;
}

Color DrawingState::stroke()
{
    return m_strokeColor;
}

void DrawingState::strokeWeight(float weight)
{
    m_strokeWidth = weight;
}

float DrawingState::strokeWeight()
{
    return m_strokeWidth;
}

void DrawingState::fill(Color color)
{
    m_fillColor = color;
}

Color DrawingState::fill()
{
    return m_fillColor;
}



void arc(float a, float b, float c, float d, float start, float stop)
{
    //DrawArc(Vector2{a, b}, c, d, start, stop, 10, RED);
}

void circle(float x, float y, float extent)
{
    DrawCircle(x, y, extent, RED);
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