/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Background
*/

#pragma once

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
             * @brief This function is used to create a sound
             *
             * @param filename file path to the sound
             * @param volume volume of the sound
             * @param islooping set to true to make it infinite or false if you want a single time
             */
            void CreateSound(std::string filename, int volume, bool islooping) {
                if (!music.openFromFile(filename))
                    std::cout << "Error while loading the music" << std::endl;
                music.setVolume(volume);
                if (islooping == true) {
                    music.setLoop(islooping);
                    music.play();
                } else
                    music.play();
            }

            void draw(sf::RenderWindow &w) {
                w.draw(this->asset);
            }

        protected:
        private:
            sf::Texture texture;
            sf::Sprite asset;
            sf::Music music;

    };
}
