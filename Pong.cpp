// Pong.cpp
#include <SFML/Graphics.hpp>
#include "batp.h"
#include "ballp.h"
#include <sstream>

using namespace sf;

int main(){
    const float WIN_W = 800.f;
    const float WIN_H = 600.f;

    RenderWindow window(VideoMode({(unsigned int)WIN_W, (unsigned int)WIN_H}), "Pong");
    window.setFramerateLimit(60);
    //scores
    int scorePlayer = 0;  // Player 1 (bottom bat, arrow keys)
    int scoreAI     = 0;  // Player 2 / AI (top bat)

    // Player 1 — bottom, controlled by Left/Right arrow keys
    // Player 2 — top,    controlled by A/D keys  (or simple AI)
    Bat player1(WIN_W / 2.f, WIN_H - 30.f, WIN_W);
    Bat player2(WIN_W / 2.f, 30.f,         WIN_W);

    // Ball — start in the centre
    Ball ball(WIN_W / 2.f, WIN_H / 2.f);

    // Font & HUD
    Font font;
    if (!font.openFromFile("KOMIKAX.TTF"))
        return -1;

    Text hud(font);
    hud.setCharacterSize(28);
    hud.setFillColor(Color::White);
    hud.setPosition({WIN_W / 2.f - 80.f, WIN_H / 2.f - 14.f});

    // Centre dashed line (cosmetic)
    RectangleShape midLine(Vector2f(WIN_W, 2.f));
    midLine.setPosition({0.f, WIN_H / 2.f - 1.f});
    midLine.setFillColor(Color(255, 255, 255, 60));

    Clock clock;

    // Game loop
    while (window.isOpen()){
        while (auto event = window.pollEvent()){
            if (event->is<Event::Closed>())
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
            window.close();

        // ---------- dt — restart EVERY frame ----------
        Time dt = clock.restart();

        // ---------- Player 1 input (arrow keys) ----------
        if (Keyboard::isKeyPressed(Keyboard::Key::Left))
            player1.moveLeft();
        else
            player1.stopLeft();

        if (Keyboard::isKeyPressed(Keyboard::Key::Right))
            player1.moveRight();
        else
            player1.stopRight();

        // ---------- Player 2 input (A / D keys) ----------
        if (Keyboard::isKeyPressed(Keyboard::Key::A))
            player2.moveLeft();
        else
            player2.stopLeft();

        if (Keyboard::isKeyPressed(Keyboard::Key::D))
            player2.moveRight();
        else
            player2.stopRight();

        // ---------- Updates ----------
        player1.update(dt);
        player2.update(dt);
        ball.update(dt);

        // ---------- Ball vs left / right walls ----------
        FloatRect ballPos = ball.getPosition();

        if (ballPos.position.x < 0 ||
            ballPos.position.x + ballPos.size.x > WIN_W){
            ball.reboundSides();
        }

        // ---------- Ball vs top wall (Player 2 scores) ----------
        if (ballPos.position.y < 0){
            ball.reboundTopBottom();
        }

        // ---------- Ball vs bottom wall (Player 1 scores) ----------
        if (ballPos.position.y + ballPos.size.y > WIN_H){
            ball.reboundTopBottom();
        }

        // ---------- Ball vs Player 1 bat ----------
        if (ball.getPosition().findIntersection(player1.getPosition())){
            ball.reboundTopBottom();
            scorePlayer++;
        }

        // ---------- Ball vs Player 2 bat ----------
        if (ball.getPosition().findIntersection(player2.getPosition())){
            ball.reboundTopBottom();
            scoreAI++;
        }

        // ---------- HUD ----------
        std::ostringstream ss;
        ss << "P1: " << scorePlayer << "   P2: " << scoreAI;
        hud.setString(ss.str());

        // ---------- Draw ----------
        window.clear(Color::Black);

        window.draw(midLine);
        window.draw(hud);
        window.draw(player1.getShape());
        window.draw(player2.getShape());
        window.draw(ball.getShape());

        window.display();
    }

    return 0;
}