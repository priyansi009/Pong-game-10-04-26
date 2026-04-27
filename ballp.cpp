// ballp.cpp
#include "ballp.h"

Ball::Ball(float startX, float startY){
    m_Shape.setRadius(10.f);
    m_Shape.setFillColor(Color::White);
    m_Shape.setOrigin({10.f, 10.f}); // center the origin
    m_Position.x = startX;
    m_Position.y = startY;
    m_Shape.setPosition(m_Position);
}

CircleShape Ball::getShape(){
    return m_Shape;
}

FloatRect Ball::getPosition(){
    return m_Shape.getGlobalBounds();
}

float Ball::getVelocity(){
    return m_Speed;
}

// Bounce horizontally (left/right walls)
void Ball::reboundSides(){
    m_DirectionX = -m_DirectionX;
}

// Bounce vertically (top/bottom walls or bat hit)
void Ball::reboundTopBottom(){
    m_DirectionY = -m_DirectionY;
}

// Reset ball to center of screen
void Ball::reset(float x, float y){
    m_Position.x = x;
    m_Position.y = y;
    m_Shape.setPosition(m_Position);

    m_DirectionX = -m_DirectionX;   // Reverse X direction each reset for variety
    m_DirectionY = 1.0f;    // Always send downward after a reset
}

void Ball::update(Time dt){
    m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
    m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
    m_Shape.setPosition(m_Position);
}