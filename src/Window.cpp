/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Window
*/

#include <Window.hpp>

Window::Window()
{
}

Window::~Window()
{
}

void Window::CreateWindow(sf::VideoMode mode, std::string name)
{
    this->window_mode = mode;
    this->window_name = name;
    this->window.create(this->window_mode, this->window_name);
    this->window.setFramerateLimit(60);
}

bool Window::IsOpen(void)
{
    return this->window.isOpen();
}

bool Window::UpdateEvent(void)
{
    return (this->window.pollEvent(this->window_event));
}

bool Window::HandleEvent(const sf::Event::EventType &type)
{
    return (this->window_event.type == type);
}

int Window::DisplayWindow(void)
{
    Draw rect;
    Event ev;
    EntitiesManager entitie;
    Bullets bull;

    sf::Sprite test2 = entitie.CreateEntitie("assets/ovni.png", {100, 100}, {0.1, 0.1});

    while (this->IsOpen()) {
        while (this->UpdateEvent()) {
            if (this->HandleEvent(sf::Event::Closed))
                return (0);
            ev.MakeSpriteMovable(test2);
        }
        this->window.clear();
        this->window.draw(test2);
        bull.Shooting(test2);
        this->window.display();
    }
    return (0);
}