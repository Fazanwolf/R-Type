/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Event
*/

#include "Engine/Engine.hpp"
#include "Engine/Event.hpp"

using namespace rtype::engine;

Event::Event()
{
}

Event::~Event()
{
}

EventType Event::ServerPlayerAction(sf::Transformable &obj_pos, EventType action)
{
    switch(action)
    {
        case(MV_UP):
            obj_pos.move(sf::Vector2f{0, -50});
        case(MV_DOWN):
            obj_pos.move(sf::Vector2f{0, 50});
        case(MV_LEFT):
            obj_pos.move(sf::Vector2f{-50, 0});
        case(MV_RIGHT):
            obj_pos.move(sf::Vector2f{50, 0});
        case(FIRE):
            //shot bullet from EManager
            return FIRE;
        default:
            break;
    }
    return NONE;
}

void Event::MakeObjectMovable(sf::Transformable &obj_pos)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        obj_pos.move(sf::Vector2f{10, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        obj_pos.move(sf::Vector2f{-10, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        obj_pos.move(sf::Vector2f{0, -10});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        obj_pos.move(sf::Vector2f{0, 10});
    }
}

void Event::MakeSpriteMovable(sf::Sprite &asset)
{
    if (asset.getPosition().x < 20) {
        asset.setPosition(sf::Vector2f(20, asset.getPosition().y));
        return;
    }

    if (asset.getPosition().x > 840) {
        asset.setPosition(sf::Vector2f(840, asset.getPosition().y));
        return;
    }
    if (asset.getPosition().y < 20) {
        asset.setPosition(sf::Vector2f(asset.getPosition().x, 20));
        return;
    }
    if (asset.getPosition().y > 560) {
        asset.setPosition(sf::Vector2f(asset.getPosition().x, 560));
        return;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        // this->clt->client->send("move right");
        asset.move(sf::Vector2f{30.f, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        // this->clt->client->send("move left");
        asset.move(sf::Vector2f{-30.f, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        // this->clt->client->send("move up");
        asset.move(sf::Vector2f{0, -30.f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        // this->clt->client->send("move down");
        asset.move(sf::Vector2f{0, 30.f});
    }
}

sf::Vector2f Event::GetMousePos(sf::RenderWindow &w)
{

    sf::Vector2i mousePos = sf::Mouse::getPosition(w);
    return w.mapPixelToCoords(mousePos);
}

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