/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Map
*/

#pragma once

#include "Engine/Engine.hpp"

/**
* @brief This namespace is for herite from engine
*/
namespace rtype::engine {

    /**
    * @brief This class is the base class for all the Map
    */
    class Map {
        public:

            /**
            * @brief Constructor for class Map
            */
            Map();

            /**
            * @brief Destructor for class Map
            */
            ~Map();

        protected:
        private:
            sf::Vector2f m_map;
            sf::Vector2f m_collision;
    };
}
