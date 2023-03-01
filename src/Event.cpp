/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Event
*/

#include "Engine/Engine.hpp"
#include "Engine/Event.hpp"

using namespace rtype::engine;

Event::Event(sk::Skaldi<sk::client::UDP, sk::server::UDP> *clt)
{
    this->clt = clt;
    // std::cout<<"client buffer = "<<this->clt->client->getBuffer()<<std::endl;
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

// std::list<sf::RectangleShape> Event::ShotBullet(std::list<sf::RectangleShape> &og)
// {
//     std::list<sf::RectangleShape> bullets = og;
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
//     {
//         sf::RectangleShape bullet;
//         bullet.setFillColor(sf::Color::White);
//         bullet.setPosition(sf::Vector2f(100,100));
//         bullet.setSize(sf::Vector2f(50,40));
//         // bullet.scale(sf::Vector2f(50,40));
//         bullets.push_back(bullet);
//     }
//     if (!bullets.empty())
//     {
//         for (auto &ammo : bullets)
//         {
//             ammo.move(sf::Vector2f{50, 0});
//         }
//         std::cerr<<"bullets"<<std::endl;
//     }
//     return bullets;
// }

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
        this->clt->client->send("move right");
        asset.move(sf::Vector2f{30.f, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        this->clt->client->send("move left");
        asset.move(sf::Vector2f{-30.f, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        this->clt->client->send("move up");
        asset.move(sf::Vector2f{0, -30.f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->clt->client->send("move down");
        asset.move(sf::Vector2f{0, 30.f});
    }
}

//test only
void Event::MakeSpriteMovable_Bis(sf::Sprite &asset)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->clt->client->send("move right");
        asset.move(sf::Vector2f{30.f, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->clt->client->send("move left");
        asset.move(sf::Vector2f{-30.f, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        this->clt->client->send("move forward");
        asset.move(sf::Vector2f{0, -30.f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        this->clt->client->send("move down");
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