/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Background
*/

#ifndef BACKGROUND_HPP_
#define BACKGROUND_HPP_
#include "Engine/Engine.hpp"

namespace rtype::components {

    class Background {
        public:
            // Background();
            // ~Background();
            void initBackground(std::string filename, sf::Vector2f pos) {
                if (!texture.loadFromFile(filename))
                    throw std::runtime_error("Error loading background");
                asset.setTexture(texture);
                asset.setScale(pos);
            }

            sf::Sprite &getSprite(void) {
                return this->asset;
            }

        protected:
        private:
            sf::Texture texture;
            sf::Sprite asset;
            sf::Time timer;

    };
}

#endif /* !BACKGROUND_HPP_ */
