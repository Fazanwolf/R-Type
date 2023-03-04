/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Event
*/

#pragma once

#include "Engine/Engine.hpp"
#include <list>
#include <queue>
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

    enum EventType
    {
        MV_LEFT,
        MV_RIGHT,
        MV_UP,
        MV_DOWN,
        FIRE,
        NONE
    };

    class Event {
        public:
            Event(sk::Skaldi<sk::client::UDP, sk::server::UDP> *clt);
            ~Event();
            void handleEvent();
            void handleInput();
            void update();
            EventType ServerPlayerAction(sf::Transformable &obj_pos, EventType action);
            void MakeObjectMovable(sf::Transformable &obj_pos);
            void MakeObjectClickable(sf::RectangleShape button);
            void MakeSpriteMovable(sf::Sprite &asset); //player move on input
            void MakeSpriteMovable_Bis(sf::Sprite &asset); //player move on input test only
            sf::Vector2f GetMousePos(sf::RenderWindow &w);
            void GetMousePos(sf::Event event);
            void GetMousePressed(sf::Event event);

            std::string getClientBuffer()
            {
                return this->clt->client->getBuffer();
            }

            void sendMessage(std::string msg)
            {
                this->clt->client->send(msg);
            }

            // std::list<sf::RectangleShape> ShotBullet(std::list<sf::RectangleShape> &bullets);
            std::queue<std::string> server_updates;

        protected:
        private:
            float velocity;
            sk::Skaldi<sk::client::UDP, sk::server::UDP> *clt;
    };
}
