/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Audio
*/

#pragma once

#include "Engine/Engine.hpp"

/**
* @brief This namespace is for herite from engine
*/
namespace rtype::engine {

    /**
    * @brief This class is the base class for all the Audio
    */
    class Audio {
        public:

            /**
            * @brief Constructor for class Button
            */
            Audio();

            /**
            * @brief Destructor for class Bullets
            */
            ~Audio();

            /**
            * @brief Function to create a sound
            *
            * @param audio audio to be create
            */

            void CreateSound(sf::Sound audio);

        protected:
        private:
            sf::Sound a_sound;
    };
}
