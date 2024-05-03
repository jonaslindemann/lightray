#pragma once

#include <raylib.h>

namespace lightray {

enum class EllipseMode {
    CENTER,
    RADIUS,
    CORNER
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

    bool drawStroke() const;

    bool drawFill() const;

    void alpha(unsigned char alpha);

    unsigned char alpha() const;

private:
    static DrawingState *m_instance;

    DrawingState()
    {}                                                      // Private constructor to prevent instantiation
    DrawingState(const DrawingState &) = delete;            // Delete copy constructor
    DrawingState &operator=(const DrawingState &) = delete; // Delete assignment operator

    // Rest of the class implementation...
    Color m_strokeColor{BLACK};
    float m_strokeWidth{1.0f};
    Color m_fillColor{BLACK};
    EllipseMode m_ellipseMode{EllipseMode::CENTER};
    bool m_drawStroke{true};
    bool m_drawFill{true};

    unsigned char m_currentAlpha{255};
};

void arc(float a, float b, float c, float d, float start, float stop);
void circle(float x, float y, float extent);
void ellipse(float x, float y, float a, float b);
void line(float x1, float y1, float x2, float y2);
void point(float x, float y);
void rect(float x, float y, float w, float h);
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

} // namespace lightray
