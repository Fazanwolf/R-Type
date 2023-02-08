/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "Engine.hpp"

namespace rtype::engine {
    class Map {
        public:
            Map();
            ~Map();

        protected:
        private:
            sf::Vector2f m_map;
            sf::Vector2f m_collision;
    };
}

#endif /* !MAP_HPP_ */
