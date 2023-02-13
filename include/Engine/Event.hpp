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
            /**
             * @brief Init a client to server
             *
             * @param clt
             */
            Event(sk::Skaldi<sk::client::UDP, sk::server::UDP> *clt);
            ~Event();
            void handleEvent();
            void handleInput();
            void update();
            /**
             * @brief Check the input of the player and return the appropriate action
             *
             * @param obj_pos
             * @param action
             * @return EventType
             */
            EventType ServerPlayerAction(sf::Transformable &obj_pos, EventType action);
            /**
             * @brief Make an object movable with the keyboard
             *
             * @param obj_pos
             */
            void MakeObjectMovable(sf::Transformable &obj_pos);
            /**
             * @brief Make an object clickable
             *
             * @param button
             */
            void MakeObjectClickable(sf::RectangleShape button);
            /**
             * @brief Make a Sprite movable with the keyboard
             *
             * @param asset
             */
            void MakeSpriteMovable(sf::Sprite &asset); //player move on input
            /**
             * @brief Make a Sprite from an another clien movable with the keyboard
             *
             * @param asset
             */
            void MakeSpriteMovable_Bis(sf::Sprite &asset); //player move on input test only
            /**
             * @brief Get the Mouse Pos object
             *
             * @param event
             */
            void GetMousePos(sf::Event event);
            /**
             * @brief Get the Mouse Pressed object
             *
             * @param event
             */
            void GetMousePressed(sf::Event event);
            /**
             * @brief Get the Client Buffer object
             *
             * @return std::string
             */
            std::string getClientBuffer()
            {
                return this->clt->client->getBuffer();
            }
            /**
             * @brief Send a message to the serveur
             *
             * @param msg
             */
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
