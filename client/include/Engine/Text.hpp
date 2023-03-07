/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include "Engine/Engine.hpp"

/**
* @brief This namespace is for herite from engine
*/
namespace rtype::engine {

    /**
    * @brief This class is the base class for all the Text
    */
    class Text {
        public:

            /**
            * @brief Constructor for class Text
            */
            Text();

            /**
            * @brief Destructor for class Text
            */
            ~Text();

        protected:
        private:
            sf::Text text_content;
            sf::Vector2f text_pos;
            sf::Font text_font;
    };
}

#endif /* !TEXT_HPP_ */
