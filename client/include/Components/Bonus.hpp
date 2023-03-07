/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Bonus
*/

#pragma once

#include "Engine/Engine.hpp"

/**
* @brief This namespace is for herite from components
*/
namespace rtype::components {

    /**
    * @brief This enum is for all bonus in the game
    */
    enum BonusTraits {
        SHIELD,
        SHOTGUN,
        SLAVE,
    };

    /**
    * @brief This class is the base class for all the bonus in the game
    */
    class Bonus {
        public:
            /**
            * @brief Constructor for class Bonus
            */
            Bonus();

            /**
            * @brief Destructor for class Bonus
            */
            ~Bonus();

        protected:
        private:
            sf::RectangleShape bonus_rect;
            sf::Sprite bonus_asset;
            sf::Vector2f bonus_pos;
    };
}
