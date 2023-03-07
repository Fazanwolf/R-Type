/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Engine
*/

#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <vector>
#include <exception>
#include "Engine/Window.hpp"
#include "Engine/Event.hpp"
#include "Entities/EntitiesManager.hpp"
#include "Components/Bullets.hpp"
#include "Components/Background.hpp"

/**
* @brief Function to create a rectangle shape at a position
*
* @param pos Position of the rectangle
*
* @return Return a rectangle shape
*/
static sf::RectangleShape createSmallRect(sf::Vector2f pos)
{
    sf::RectangleShape tmp;
    tmp.setSize({1,1});
    tmp.setPosition(pos);
    return tmp;
}

/**
* @brief This namespace is for herite from engine
*/
namespace rtype::engine {

    /**
    * @brief This class is the base class for all the Engine
    */
    class Engine {
        public:

            /**
            * @brief Constructor for class Engine
            */
            Engine();

            /**
            * @brief Destructor for class Engine
            */
            ~Engine();

        protected:
        private:
    };
}
