/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Properties
*/

#ifndef PROPERTIES_HPP_
#define PROPERTIES_HPP_

#include "Engine/Engine.hpp"

namespace rtype::entities {

    class Entity {
        public:
            /*
            * @brief Default constructor
            */
            Entity();
            /*
            * @brief Default destructor
            */
            ~Entity();
            /*
            * @brief Return the position of the entity in 2D
            */
            virtual sf::Vector2f getPos(void) = 0;
            /*
            * @brief Return the X position of the entity
            */
            virtual float getX(void) = 0;
            /*
            * @brief Return the Y position of the entity
            */
            virtual float getY(void) = 0;
            /*
            * @brief Get the current Velocity of the entity
            */
            virtual float getVelocity(void) = 0;
            /*
            * @brief Set the Position of the entity
            * @param Position of the entity
            */
            virtual void setPosition(sf::Vector2f const &position) = 0;
            /*
            * @brief Set the Velocity of the entity
            * @param Velocity of the entity
            */
            virtual void setVelocity(sf::Vector2f const &velocity) = 0;

        protected:
        private:
            sf::RectangleShape e_rect;
            sf::Sprite e_asset;
            sf::Vector2f e_position;
            int e_health;
            int e_maxBonus;
    };
}

#endif /* !PROPERTIES_HPP_ */
