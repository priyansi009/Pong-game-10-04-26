#include "ballp.h"
Ball::Ball(float startX, float startY){
	m_Shape.setRadius(10);
	m_Position.x = 960;
	m_Position.y = 540;
	m_Shape.setFillColor(Color::White);
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

void Ball::reboundSides(){
	m_DirectionX = -m_DirectionX;
}

void Ball::reboundBatOrTop(){
	m_DirectionY = -m_DirectionY;
}

void Ball::reboundBottom(){
	m_Position.y = 540;
	m_Position.x = 960;
}

void Ball::update(Time dt){
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
	m_Shape.setPosition(m_Position);
}