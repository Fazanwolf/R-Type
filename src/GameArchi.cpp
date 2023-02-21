/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** GameArchi
*/

#include "system/GameArchi.hpp"

namespace rtype {

    GameArchi::GameArchi()
    {
    }

    GameArchi::~GameArchi()
    {
    }

    void GameArchi::CreateEntities(std::string filename, sf::Vector2f pos, sf::Vector2f scale)
    {
        sf::Sprite asset;

        if (!texture.loadFromFile(filename))
            std::cout << "error" << std::endl;
        asset.setTexture(texture);
        asset.setPosition(pos);
        asset.scale(scale);
    }

    void GameArchi::MakeEntityMovable(sf::Sprite &asset)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        asset.move(sf::Vector2f{30.f, 0});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            asset.move(sf::Vector2f{-30.f, 0});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            asset.move(sf::Vector2f{0, -30.f});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            asset.move(sf::Vector2f{0, 30.f});
    }

    void GameArchi::CreateWindow(sf::VideoMode mode, std::string name)
    {
        this->window_mode = mode;
        this->window_name = name;
        this->window.create(this->window_mode, this->window_name);
        this->window.setFramerateLimit(60);
        this->winClock = sf::Clock();
    }

    bool GameArchi::IsOpen(void)
    {
        return this->window.isOpen();
    }
    bool GameArchi::UpdateEvent(void)
    {
        return (this->window.pollEvent(this->win_event));
    }

    bool GameArchi::HandleEvent(const sf::Event::EventType &type)
    {
        return (this->win_event.type == type);
    }

    void GameArchi::CloseWindow()
    {
        this->window.close();
    }

    void GameArchi::ClearWindow()
    {
        this->window.clear();
    }

    void GameArchi::DisplayWindow()
    {
        this->window.display();
    }
}