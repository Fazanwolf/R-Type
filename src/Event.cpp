/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Event
*/

#include "../include/Engine/Event.hpp"

Event::Event()
{
}

Event::~Event()
{
}

void Event::MakeObjectMovable(sf::RectangleShape &obj_pos)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        obj_pos.move(sf::Vector2f{50, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        obj_pos.move(sf::Vector2f{-50, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        obj_pos.move(sf::Vector2f{0, -50});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        obj_pos.move(sf::Vector2f{0, 50});
    }
}

void Event::MakeSpriteMovable(sf::Sprite &asset)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        asset.move(sf::Vector2f{30.f, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        asset.move(sf::Vector2f{-30.f, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        asset.move(sf::Vector2f{0, -30.f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        asset.move(sf::Vector2f{0, 30.f});
    }
}

// void Event::MakeObjectClickable(sf::RectangleShape button)
// {
//     sf::Mouse mouse;

// }

void Event::GetMousePos(sf::Event event)
{
    if (event.type == sf::Event::MouseMoved) {
        std::cout << "mouse x: " << event.mouseMove.x << std::endl;
        std::cout << "mouse y: " << event.mouseMove.y << std::endl;
    }
}

void Event::GetMousePressed(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Right) {
            std::cout << "Right Mouse Pressed" << std::endl;
            std::cout << "mouse x: " << event.mouseButton.x << std::endl;
            std::cout << "mouse y: " << event.mouseButton.y << std::endl;
        }
    }
}