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

    /**
     * @brief This class is used to create background
     *
     */
    class Background {
        public:
            Background() {};
            ~Background() {};
            /**
             * @brief This function is used to init the background
             *
             * @param filename file path to the texture
             * @param pos the position of the background in the window
             */
            void initBackground(std::string filename, sf::Vector2f pos) {
                if (!texture.loadFromFile(filename))
                    throw std::runtime_error("Error loading background");
                asset.setTexture(texture);
                asset.setScale(pos);
            }

            /**
             * @brief This function is used to get the sprite of the background
             *
             * @return sf::Sprite
             */
            sf::Sprite &getSprite(void) {
                return this->asset;
            }

            /**
             * @brief This function is used to draw the background
             *
             * @param w the window where you want to draw the background
             */
            void draw(sf::RenderWindow &w) {
                w.draw(this->asset);
            }

        protected:
        private:
            sf::Texture texture;
            sf::Sprite asset;

    };
}

#endif /* !BACKGROUND_HPP_ */