/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Window
*/

#include "Engine/Window.hpp"
#include <list>

using namespace rtype;
using namespace rtype::engine;

Window::Window()
{
}

Window::~Window()
{
}

void Window::nWindow(sf::VideoMode mode, std::string name)
{
    this->window_mode = mode;
    this->window_name = name;
    this->window.create(this->window_mode, this->window_name);
    this->window.setFramerateLimit(60);
    this->winClock = sf::Clock();
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

// void init_base(entities::EntitiesManager &em, int nb_players)
// {
//     for(int i = 0; i != nb_players; i++)
//         em.NewEntity("assets/ovni.png", {100, 100}, {0.1, 0.1});

//     em.NewEntity("assets/ovni.png", {600, 100}, {0.2, 0.2});
// }

int Window::DisplayWindow(void)
{
    // float timeAsSeconds;
//    engine::Event ev(this->window);
    entities::EntitiesManager entitie;
    components::Bullets bull;

    // init_base(entitie, 2);
    // sf::Sprite test2 = entitie.CreateEntitie("assets/ovni.png", {100, 100}, {0.1, 0.1});
    // sf::Sprite mob = entitie.CreateEntitie("assets/ovni.png", {300, 100}, {1.3, 1.3});

    while (this->IsOpen()) {
        // t_clock();
        while (this->UpdateEvent()) { //should only handle states
            if (this->HandleEvent(sf::Event::Closed))
                return (0);
            // ev.MakeSpriteMovable(test2);
            // ev.MakeSpriteMovable(entitie.getSprite(0));
        }
        // bull.ShootBullet(entitie.getSprite(0));
        // std::cerr<<test2.getGlobalBounds().intersects(mob.getGlobalBounds())<<std::endl;
        // if (bull.update(entitie.getSprite(2).getGlobalBounds())) {
        //     entitie.getSprite(2).setScale(sf::Vector2f(0,0));
        // }

        this->window.clear();
        // for (auto& ammo : bull.getBulletList())
        // {
        //     if (bull.getBulletList().empty())
        //         std::cerr<<"ERROR no bullets"<<std::endl;
        //     this->window.draw(ammo);
        // }
        // this->window.draw(entitie.getSprite(0));
        // this->window.draw(entitie.getSprite(2));
        this->window.display();
    }
    return (0);
}