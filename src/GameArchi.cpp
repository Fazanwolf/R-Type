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
        this->window.clear(sf::Color::Black);
    }

    void GameArchi::DisplayWindow()
    {
        this->window.display();
    }

    void GameArchi::CreateText(std::string name, int size, std::string fontpath, sf::Vector2f pos, sf::Color color)
    {
        sf::Text text;
        sf::Font font;

        if (!font.loadFromFile(fontpath))
            std::cout << "error" << std::endl;
        text.setFont(font);
        text.setString(name);
        text.setCharacterSize(size);
        text.setFillColor(color);
        text.setPosition(pos);
        this->window.draw(text);
    }

    void GameArchi::Menu()
    {
        sf::Mouse mouse;

        CreateText("Join a Session", 50, "assets/arial.ttf", {300, 300}, sf::Color::White);
        CreateText("Quit", 50, "assets/arial.ttf", {300, 500}, sf::Color::White);
        if (mouse.getPosition(this->window).x >= 200 && mouse.getPosition(this->window).x <= 300 && mouse.getPosition(this->window).y >= 100 && mouse.getPosition(this->window).y <= 150) {
            CreateText("Join a Session", 50, "assets/arial.ttf", {300, 300}, sf::Color::Red);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                std::cout << "youhou" << std::endl;
            }
        }
        this->window.display();
    }

    void GameArchi::CreateBackground(std::string filename)
    {
        static sf::Texture texture;
        static sf::Sprite sprite;
        static sf::Time timer;

        if (!texture.loadFromFile(filename))
            std::cout << "error" << std::endl;
        timer = this->winClock.getElapsedTime();
        sprite.setTexture(texture);
        sprite.setScale(1.5, 1.5);
        if (timer.asMilliseconds() >= 0.4) {
            std::cout << "pass" << std::endl;
            sprite.setPosition(sprite.getPosition().x - 10, sprite.getPosition().y);
            this->winClock.restart();
        }

        this->window.draw(sprite);
    }

    void GameArchi::CreateAudio(std::string filename, int volume, bool islooping)
    {
        static sf::Music music;

        if (!music.openFromFile(filename))
            std::cout << "error" << std::endl;
        music.setVolume(volume);
        if (islooping == true) {
            music.setLoop(islooping);
            music.play();
        } else
            music.play();
    }
}