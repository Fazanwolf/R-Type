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
    bool OnClick() = 0;
    bool OnHover() = 0;
    bool OnLeave() = 0;
}

class Bouton : public IButton {
    public:
        // Bouton(std::string path, std::string text) {
            // 
        // };
        Bouton(sf::Color color, std::string text) {
            _shape.setFillColor(color);
            _text.setString(text);
            _shape.setSize(sf::Vector2f(100, 100));
        };
        Bouton();
        ~Bouton();

        void setPosition(sf::Vector2f nPos) { this->_shape.move };

        template <typename T, typename fpara>
        void OnClick(fpara parameter, std::function<T(fpara)> func) {
            //update button appearance here
            return func(parameter);
        };


        void OnLeave() override {}
        void OnClick() override {}
        void OnHover() override {
            //update button appearance here
            return;
        };
    
    protected:
        Sf::Shape _shape;
        Sf::Text _text;
        Sf::Texture _texture;
        
};

#endif /* !BOUTON_HPP_ */
