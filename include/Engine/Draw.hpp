/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Draw
*/

#ifndef DRAW_HPP_
#define DRAW_HPP_

#include "Engine/Engine.hpp"

namespace rtype::engine {

    class Draw {
        public:
            Draw();
            ~Draw();
            /**
             * @brief Create a rectangle
             * 
             * @param height 
             * @param width 
             * @param pos 
             * @return sf::RectangleShape 
             */
            sf::RectangleShape DrawRectangle(int height, int width, sf::Vector2f pos);
            /**
             * @brief Create a sphere
             * 
             * @param radius 
             * @return sf::CircleShape 
             */
            sf::CircleShape DrawSphere(int radius);
            /**
             * @brief Set the Texture To Object object
             * 
             * @param texture 
             * @param posRect 
             */
            void SetTextureToObject(sf::Texture texture, sf::IntRect posRect);
            /**
             * @brief Set the Texture To Circle object
             * 
             * @param circle 
             * @param texture 
             * @param posRect 
             */
            void SetTextureToCircle(sf::CircleShape circle, sf::Texture texture, sf::IntRect posRect);
            /**
             * @brief Set the Texture To Rectangle object
             * 
             * @param rectangle 
             * @param texture 
             * @param posRect 
             */
            void SetTextureToRectangle(sf::RectangleShape rectangle, sf::Texture texture, sf::IntRect posRect);

        protected:
        private:
    };
}

#endif /* !DRAW_HPP_ */
