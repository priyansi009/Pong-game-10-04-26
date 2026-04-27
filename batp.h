// batp.h
#ifndef BAT_H
#define BAT_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Bat
{
private:
    Vector2f m_Position;
    RectangleShape m_Shape;
    float m_Speed = 600.0f;
    bool m_MovingRight = false;
    bool m_MovingLeft  = false;

    float m_WindowWidth; // store window width for boundary clamping

public:
    Bat(float startX, float startY, float windowWidth);
    FloatRect getPosition();
    RectangleShape getShape();
    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();
    void update(Time dt);
};

#endif