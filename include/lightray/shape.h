#pragma once

#include <raylib.h>

namespace lightray {

enum class EllipseMode {
    CENTER,
    RADIUS,
    CORNER
};

enum class RectMode {
	CORNER,
	CORNERS,
	CENTER,
	RADIUS
};

class DrawingState {
public:
    static DrawingState *instance()
    {
        if (m_instance == nullptr)
        {
            m_instance = new DrawingState();
        }
        return m_instance;
    }

    // Rest of the class implementation...
    void stroke(Color color);
    Color stroke() const;

    void strokeWeight(float weight);
    float strokeWeight() const;

    void fill(Color color);
    Color fill() const;

    void ellipseMode(EllipseMode mode);
    EllipseMode ellipseMode();

    void noStroke();
    void noFill();
    void noGradientFill();

    bool drawStroke() const;
    bool drawFill() const;
    bool drawGradient() const;

    void alpha(unsigned char alpha);
    unsigned char alpha() const;

    void gradient(Color color1, Color color2);
    void gradient1(Color color);
    void gradient2(Color color);
    Color gradient1() const;
    Color gradient2() const;

    void rectMode(RectMode mode);
    RectMode rectMode() const;

private:
    static DrawingState *m_instance;

    DrawingState()
    {}                                                      // Private constructor to prevent instantiation
    DrawingState(const DrawingState &) = delete;            // Delete copy constructor
    DrawingState &operator=(const DrawingState &) = delete; // Delete assignment operator

    // Rest of the class implementation...
    Color m_strokeColor{BLACK};
    float m_strokeWidth{1.0f};
    Color m_fillColor{WHITE};
    EllipseMode m_ellipseMode{EllipseMode::CENTER};
    RectMode m_rectMode{RectMode::CORNER};
    bool m_drawStroke{true};
    bool m_drawFill{true};
    bool m_drawGradient{false};

    Color m_gradientColor1{RED};
    Color m_gradientColor2{BLUE};

    unsigned char m_currentAlpha{255};
};

void arc(float a, float b, float c, float d, float start, float stop);
void circle(float x, float y, float extent);
void ellipse(float x, float y, float a, float b);
void line(float x1, float y1, float x2, float y2);
void point(float x, float y);
void rect(float x, float y, float w, float h);
void rect(float x, float y, float w, float h, float r);
void square(float x, float y, float extent);
void triangle(float x1, float y1, float x2, float y2, float x3, float y3);
void quad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);

void stroke(Color color);
Color stroke();

void strokeWeight(float weight);
float strokeWeight();

void fill(Color color);
Color fill();

void ellipseMode(EllipseMode mode);
EllipseMode ellipseMode();

void noStroke();
void noFill();

bool drawStroke();
bool drawFill();

void alpha(unsigned char alpha);
unsigned char alpha();

void gradient(Color color1, Color color2);
void gradient1(Color color);
void gradient2(Color color);
Color gradient1();
Color gradient2();

void noGradientFill();
bool drawGradient();

void rectMode(RectMode mode);
RectMode rectMode();

} // namespace lightray
