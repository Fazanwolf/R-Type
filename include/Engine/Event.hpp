/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Event
*/

#pragma once

#include "Engine/Engine.hpp"
#include <list>
#include <Skaldi.hpp>

namespace rtype::engine {
    enum controller {
        Z,
        Q,
        S,
        D,
        ECHAP,
        SPACE
    };


    class Event {
        public:
            Event(sk::Skaldi<sk::client::UDP, sk::server::UDP> *clt);
            ~Event();
            void handleEvent();
            void handleInput();
            void update();
            void MakeObjectMovable(sf::RectangleShape &obj_pos);
            void MakeObjectClickable(sf::RectangleShape button);
            void MakeSpriteMovable(sf::Sprite &asset);
            void GetMousePos(sf::Event event);
            void GetMousePressed(sf::Event event);
            std::list<sf::RectangleShape> ShotBullet(std::list<sf::RectangleShape> &bullets);

        protected:
        private:
            float velocity;
            sk::Skaldi<sk::client::UDP, sk::server::UDP> *clt;
    };
}
