/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include "Engine/Engine.hpp"

namespace rtype::components {

    /**
     * @brief This class is used to create a text
     *
     */
    class Text {
        public:
            Text() {};
            ~Text() {};

            /**
             * @brief This function is used to create a text
             *
             * @param name the name of the text
             * @param size the size of the text
             * @param fontpath the path of the font
             * @param pos the position of the text
             * @param color the color of the text
             */
            void CreateText(std::string name, int size, std::string fontpath, sf::Vector2f pos, sf::Color color)
            {
                sf::Text text;
                sf::Font font;

                if (!font.loadFromFile(fontpath))
                    std::cout << "error" << std::endl;
                text.setFont(font);
                text.setString(name);
                text.setCharacterSize(size);
                text.setFillColor(color);
                text.setPosition(pos);
            }

            /**
             * @brief Get the Text object
             *
             * @return sf::Text
             */
            sf::Text getText(void) {
                return this->text;
            }

            /**
             * @brief This function is used to draw the background
             *
             * @param w the window where you want to draw the background
             */
            void draw(sf::RenderWindow &w) {
                w.draw(this->text);
            }

        protected:
        private:
            sf::Text text;
            sf::Font font;
    };
}

#endif /* !TEXT_HPP_ */
