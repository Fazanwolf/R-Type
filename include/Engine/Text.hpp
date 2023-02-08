/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include "Engine.hpp"

namespace rtype::engine {

    class Text {
        public:
            Text();
            ~Text();

        protected:
        private:
            sf::Text text_content;
            sf::Vector2f text_pos;
            sf::Font text_font;
    };
}

#endif /* !TEXT_HPP_ */
