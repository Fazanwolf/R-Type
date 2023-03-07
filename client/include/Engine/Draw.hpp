/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Draw
*/

#pragma once

#include "Engine/Engine.hpp"

namespace rtype::engine {

    class Draw {
        public:
            Draw();
            ~Draw();
            sf::RectangleShape DrawRectangle(int height, int width, sf::Vector2f pos);
            sf::CircleShape DrawSphere(int radius);
            void SetTextureToObject(sf::Texture texture, sf::IntRect posRect);
            void SetTextureToCircle(sf::CircleShape circle, sf::Texture texture, sf::IntRect posRect);
            void SetTextureToRectangle(sf::RectangleShape rectangle, sf::Texture texture, sf::IntRect posRect);

        protected:
        private:
    };
}
