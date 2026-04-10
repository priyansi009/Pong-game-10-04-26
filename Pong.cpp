#include <SFML/Graphics.hpp>
#include "batp.h"
#include "ballp.h"
#include <iostream>
#include <sstream>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode({800, 600}), "Pong");

    //View view({0, 0}, {1920, 1080});
    //window.setView(view);

    int score = 0;
    int lives = 3;

    Bat bat(900, 1000);
    Ball ball(960, 540);   // ✅ better start


    Font font;
    if (!font.openFromFile("KOMIKAX.TTF")) {
        // Handle error
        return -1;
    }
    sf::Clock gameClock;
    sf::Time dt = gameClock.restart();

    std::cout << ball.getPosition().position.x << std::endl;

    Text hud(font);  // ✅ FIXED

    while (window.isOpen()){
    while (auto event = window.pollEvent()){
        if (event->is<Event::Closed>())
            window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
            window.close();
    }


        // Bat movement
        if (Keyboard::isKeyPressed(Keyboard::Key::Left))
            bat.moveLeft();
        else
            bat.stopLeft();

        if (Keyboard::isKeyPressed(Keyboard::Key::Right))
            bat.moveRight();
        else
            bat.stopRight();



        
        
        bat.update(dt);
        ball.update(dt);

        // Bottom
        if (ball.getPosition().position.y > 1080){
            ball.reboundBottom();
            lives--;

        if (lives < 1){
            score = 0;
            lives = 3;
            }
        }

        //top
        if (ball.getPosition().position.y < 0){
            ball.reboundBatOrTop();
            score++;
        }

        // Sides
        if (ball.getPosition().position.x < 0 ||
            ball.getPosition().position.x + ball.getPosition().size.x > 1920)
            {
            ball.reboundSides();
    }

        // Bat collision
        if (ball.getPosition().findIntersection(bat.getPosition())){
            ball.reboundBatOrTop();
            }

        window.clear(Color::Black);
        //window.draw(hud);
        //window.draw(bat.getShape());
        //window.draw(ball.getShape());
        CircleShape circle(50);
        circle.setFillColor(Color::Red);
        circle.setPosition({500.f, 500.f});
        window.draw(circle);
        window.display();
    }

    
    