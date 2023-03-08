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

/**
* @brief This namespace is for herite from engine
*/
namespace rtype::engine {

    /**
    * @brief This enum is for all controller
    */
    enum controller {
        Z,
        Q,
        S,
        D,
        ECHAP,
        SPACE
    };

    /**
    * @brief This enum is for event type
    */
    enum EventType
    {
        MV_LEFT,
        MV_RIGHT,
        MV_UP,
        MV_DOWN,
        FIRE,
        NONE
    };

    /**
    * @brief This class is the base class for all the Event
    */
    class Event {
        public:

            /**
            * @brief Constructor for class Button to set the server and the client
            */
            Event();

            /**
            * @brief Destructor for class Event
            */
            ~Event();

            /**
            * @brief Function to handle event
            */
            void handleEvent();

            /**
            * @brief Function to handle input
            */
            void handleInput();

            /**
            * @brief Function to update event
            */
            void update();

            /**
            * @brief Function for the server to return an event type
            *
            * @param obj_pos Position of the object
            * @param action Action to do
            *
            * @return Return an event type
            */
            EventType ServerPlayerAction(sf::Transformable &obj_pos, EventType action);

            /**
            * @brief Function to make an object movable
            *
            * @param obj_pos Position of the object
            */
            void MakeObjectMovable(sf::Transformable &obj_pos);

            /**
            * @brief Function to make an object clickable
            *
            * @param button Rectangle shape of a button
            */
            void MakeObjectClickable(sf::RectangleShape button);

            /**
            * @brief Function to make an sprite movable
            *
            * @param asset Asset to move
            */
            void MakeSpriteMovable(sf::Sprite &asset); //player move on input

            /**
            * @brief Function to make an sprite movable (bis)
            *
            * @param asset Asset to move
            */
            void MakeSpriteMovable_Bis(sf::Sprite &asset); //player move on input test only

            /**
            * @brief Function to get the position of the mouse
            *
            * @param w Window of the game
            *
            * @return The position of the mouse in a Vector2f
            */
            sf::Vector2f GetMousePos(sf::RenderWindow &w);

            /**
            * @brief Function to get the position of the mouse
            *
            * @param event Event class
            */
            void GetMousePos(sf::Event event);

            /**
            * @brief Function to know if the mouse pressed
            *
            * @param event Event class
            */
            void GetMousePressed(sf::Event event);

            // std::string getClientBuffer()
            // {
            //     return gClt->getBuffer();
            // }

            // std::list<sf::RectangleShape> ShotBullet(std::list<sf::RectangleShape> &bullets);
            std::queue<std::string> server_updates;

        protected:
        private:
            float velocity;
    };
}
