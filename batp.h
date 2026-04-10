#ifndef BAT_H
#define BAT_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Bat{
private:
    Vector2f m_Position;
    RectangleShape m_Shape;
    float m_Speed=600.0f;
    bool m_MovingRight=false;
    bool m_MovingLeft = false; 
    
public:
    // Constructor
    Bat(float startX, float startY);
    // Get position
    FloatRect getPosition();
    // Get shape
    RectangleShape getShape();
    // Movement controls
    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();

    // Update bat position
    void update(Time dt);
};
#endif