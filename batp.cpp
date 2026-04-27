#include "batp.h"

Bat::Bat(float startX, float startY, float windowWidth){
    m_WindowWidth = windowWidth;
    m_Position.x  = startX;
    m_Position.y  = startY;

    m_Shape.setSize(Vector2f(80.f, 10.f));  // wider bat, easier to see
    m_Shape.setOrigin({40.f, 5.f});         // center the origin
    m_Shape.setFillColor(Color::White);
    m_Shape.setPosition(m_Position);
}

FloatRect Bat::getPosition(){
    return m_Shape.getGlobalBounds();
}

RectangleShape Bat::getShape(){
    return m_Shape;
}

void Bat::moveLeft(){
    m_MovingLeft  = true;
    m_MovingRight = false;
}

void Bat::moveRight(){
    m_MovingRight = true;
    m_MovingLeft  = false;
}

void Bat::stopLeft(){
    m_MovingLeft = false;
}

void Bat::stopRight(){
    m_MovingRight = false;
}

void Bat::update(Time dt){
    if (m_MovingLeft){
        // Don't go past left wall (account for centered origin)
        if (m_Position.x - 40.f > 0)
            m_Position.x -= m_Speed * dt.asSeconds();
    }

    if (m_MovingRight){
        // Don't go past right wall (account for centered origin)
        if (m_Position.x + 40.f < m_WindowWidth)
            m_Position.x += m_Speed * dt.asSeconds();
    }

    m_Shape.setPosition(m_Position);
}