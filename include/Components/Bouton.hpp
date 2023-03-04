/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Bouton
*/

#include "Engine/Engine.hpp"
#include <functional>

#ifndef BOUTON_HPP_
#define BOUTON_HPP_

class IButton
{
    public:
        virtual bool OnClick() = 0;
        virtual bool OnHover() = 0;
        virtual bool OnLeave() = 0;
};

class Bouton : public IButton {
    public:
        // Bouton(std::string path, std::string text) {
            // 
        // };

        Bouton(sf::Color color, std::string text) {
            this->text.setString(text);
            this->rShape.setFillColor(color);
            this->rShape.setScale(sf::Vector2f(100, 100));
        };

        Bouton() {};
        ~Bouton() {};

        void setPosition(sf::Vector2f nPos) { this->rShape.move(nPos); };

        template <typename T, typename fpara>
        bool OnClick(fpara parameter, std::function<T(fpara)> func) {
            //update button appearance here
            return func(parameter);
        };

        bool OnLeave() override {
            return false;
        }

        bool OnClick() override {
            return false;
        }

        bool OnHover() override {
            //update button appearance here
            return false;
        };
    
    protected:
        sf::RectangleShape rShape;
        sf::CircleShape cShape;
        sf::Text text;
        sf::Texture texture;
        
};

#endif /* !BOUTON_HPP_ */
