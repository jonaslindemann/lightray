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
{
	m_ellipseMode = mode;
}

EllipseMode DrawingState::ellipseMode()
{
    return m_ellipseMode;
}

void DrawingState::noStroke()
{
    m_drawStroke = false;
}

void DrawingState::noFill()
{
    m_drawFill = false;
    m_drawGradient  = false;
}

void DrawingState::noGradientFill()
{
	m_drawGradient = false;
}

bool DrawingState::drawStroke() const
{
    return m_drawStroke;
}

bool DrawingState::drawFill() const
{
    return m_drawFill;
}

bool DrawingState::drawGradient() const
{
    return m_drawGradient;
}

void DrawingState::alpha(unsigned char alpha)
{
    m_strokeColor.a = alpha;
    m_fillColor.a = alpha;
    m_gradientColor1.a = alpha;
    m_gradientColor2.a = alpha; 
}

unsigned char DrawingState::alpha() const
{
    return m_fillColor.a;
}

void DrawingState::gradient(Color color1, Color color2)
{
	m_gradientColor1 = color1;
	m_gradientColor2 = color2;
    m_drawGradient = true;
}

void DrawingState::gradient1(Color color)
{
	m_gradientColor1 = color;
    m_drawGradient = true;
}

void DrawingState::gradient2(Color color)
{
	m_gradientColor2 = color;
    m_drawGradient = true;
}

Color DrawingState::gradient1() const
{
    return m_gradientColor1;
}

Color DrawingState::gradient2() const
{
	return m_gradientColor2;
}

void DrawingState::rectMode(RectMode mode)
{
    m_rectMode = mode;
}

RectMode DrawingState::rectMode() const
{
    return m_rectMode;
}

void arc(float a, float b, float c, float d, float start, float stop)
{
    // DrawArc(Vector2{a, b}, c, d, start, stop, 10, RED);
}

void circle(float x, float y, float extent)
{
    if (ellipseMode() == EllipseMode::CORNER)
        x += extent / 2, y += extent / 2;

    if (drawGradient())
        DrawCircleGradient(x, y, extent/2.0f, gradient1(), gradient2());
    else
        if (drawFill())
            DrawCircle(x, y, extent/2.0f, fill());

    float r1 = extent/2.0f - strokeWeight() / 2;
    float r2 = extent/2.0f + strokeWeight() / 2;

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

    if (rectMode() == RectMode::CORNERS)
    {
		w = w - x;
		h = h - y;
	}
    else if (rectMode() == RectMode::CENTER)
    {
		x = x - w / 2;
		y = y - h / 2;
	}

    if (drawGradient())
		DrawRectangleGradientH(x, y, w, h, gradient1(), gradient2());
	else
		if (drawFill())
			DrawRectangle(x, y, w, h, fill());

    if (drawStroke())
        DrawRectangleLinesEx(Rectangle{x, y, w, h}, strokeWeight(), stroke());
}

void rect(float x, float y, float w, float h, float r)
{

    if (rectMode() == RectMode::CORNERS)
    {
        w = w - x;
        h = h - y;
    }
    else if (rectMode() == RectMode::CENTER)
    {
        x = x - w / 2;
        y = y - h / 2;
    }

    if (drawFill())
        DrawRectangleRounded(Rectangle{x, y, w, h}, r, 10, fill());

    if (drawStroke())
        DrawRectangleRoundedLines(Rectangle{x, y, w, h}, r, 10, strokeWeight(), stroke());
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

EllipseMode ellipseMode()
{
    return DrawingState::instance()->ellipseMode();
}

void ellipseMode(EllipseMode mode)
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

void alpha(unsigned char alpha)
{
	DrawingState::instance()->alpha(alpha);
}

unsigned char alpha()
{
	return DrawingState::instance()->alpha();
}

void gradient(Color color1, Color color2)
{
	DrawingState::instance()->gradient(color1, color2);
}

void gradient1(Color color)
{
	DrawingState::instance()->gradient1(color);
}

void gradient2(Color color)
{
	DrawingState::instance()->gradient2(color);
}

Color gradient1()
{
	return DrawingState::instance()->gradient1();
}

Color gradient2()
{
	return DrawingState::instance()->gradient2();
}

void noGradientFill()
{
	DrawingState::instance()->noGradientFill();
}

bool drawGradient()
{
	return DrawingState::instance()->drawGradient();
}

void rectMode(RectMode mode)
{
	DrawingState::instance()->rectMode(mode);
}

RectMode rectMode()
{
	return DrawingState::instance()->rectMode();
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
