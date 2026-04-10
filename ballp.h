// ball.h
#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Ball
{
private:
    Vector2f m_Position;
    CircleShape m_Shape;
    float m_Speed = 400.0f;     // better balanced speed
    float m_DirectionX = 0.5f;
    float m_DirectionY = 0.5f;

public:
    // Constructor
    Ball(float startX, float startY);
    FloatRect getPosition();      // Get position
    CircleShape getShape();       // Get shape
    float getVelocity();           // Get speed
    void reboundSides();         // Bounce functions
    void reboundBatOrTop();
    void reboundBottom();
    void update(Time dt);      // Update position
};

#endif