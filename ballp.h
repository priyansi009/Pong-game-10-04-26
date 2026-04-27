// ballp.h
#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Ball
{
private:
    Vector2f m_Position;
    CircleShape m_Shape;
    float m_Speed = 400.0f;
    float m_DirectionX = 1.0f;
    float m_DirectionY = 1.0f;

public:
    Ball(float startX, float startY);
    FloatRect getPosition();
    CircleShape getShape();
    float getVelocity();
    void reboundSides();
    void reboundTopBottom();   // bounce off top or bottom wall
    void reset(float x, float y); // reset ball to center
    void update(Time dt);
};

#endif