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

namespace rtype::components
{
    class IButton
    {
        public:
            virtual bool OnClick() = 0;
            virtual bool OnHover() = 0;
            virtual bool OnLeave() = 0;
            virtual void Draw(rtype::engine::Window &w) = 0;
            virtual bool isPointInside(sf::Vector2f point) = 0;
    };

    typedef enum STATEBUTTONS
    {
        //MAINSTATE_substate
        PLAY,
        QUIT,
        OPTION,
        MENU,
        LOBBY,
        WELCOME,
        NONE
    };

    class Bouton : public IButton {
        public:
    
            Bouton(sf::Color color, std::string text, sf::Vector2f pos, sf::Vector2f size) {
                this->text.setString(text);
                this->rShape.setFillColor(color);
                this->rShape.setSize(size); //base test is 200, 60
                this->rShape.setPosition(pos); // base pos is 440, 200
                type = NONE;
            };
    
            Bouton() {};
            ~Bouton() {};
    
            bool isPointInside(sf::Vector2f point) override
            {
                return this->rShape.getGlobalBounds().contains(point);
            }

            void Draw(rtype::engine::Window &w) override {
                w.Draw(this->rShape);
            };

            void setPosition(sf::Vector2f nPos) {
                this->rShape.move(nPos);
            };

            // template <typename T, typename fpara>
            // bool execOnClick(fpara parameter, std::function<T(fpara)> func) {
            //     //update button appearance here
            //     return func(parameter);
            // };
    
            bool OnLeave() override {
                return false;
            }
    
            bool OnClick() override {
                std::string s(this->text.getString().toAnsiString());
                std::cout<<s<<std::endl;
                return false;
            }
    
            bool OnHover() override {
                //update button appearance here
                return false;
            };
            
            STATEBUTTONS getType()
            {
                std::string s(this->text.getString().toAnsiString());

                if (s.compare("PLAY") == 0)
                    return PLAY;
                if (s.compare("QUIT") == 0)
                    return QUIT;
                if (s.compare("OPTION") == 0)
                    return OPTION;
                if (s.compare("WELCOME") == 0)
                    return WELCOME;
                if (s.compare("MENU") == 0)
                    return MENU;
                if (s.compare("LOBBY") == 0)
                    return LOBBY;
                else
                    return NONE;
            }

        public:
            STATEBUTTONS type;
    
        protected:
            sf::RectangleShape rShape;
            sf::Text text;
            // sf::Texture texture;            
    };

};

#endif /* !BOUTON_HPP_ */
