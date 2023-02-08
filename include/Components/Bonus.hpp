/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Bonus
*/

#ifndef BONUS_HPP_
#define BONUS_HPP_

#include "Engine/Engine.hpp"

namespace rtype::components {

    enum BonusTraits {
        SHIELD,
        SHOTGUN,
        SLAVE,
    };

    class Bonus {
        public:
            Bonus();
            ~Bonus();

        protected:
        private:
            sf::RectangleShape bonus_rect;
            sf::Sprite bonus_asset;
            sf::Vector2f bonus_pos;
    };
}

#endif /* !BONUS_HPP_ */
