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

/**
* @brief This namespace is for herite from components
*/
namespace rtype::components
{

    /**
    * @brief This class is the base class for all the button interface
    */
    class IButton
    {
        public:
            virtual bool OnClick() = 0;
            virtual bool OnHover() = 0;
            virtual bool OnLeave() = 0;
            virtual void Draw(rtype::engine::Window &w) = 0;
            virtual bool isPointInside(sf::Vector2f point) = 0;
    };

    /**
    * @brief This enum is for all state of button
    */
    typedef enum STATEBUTTONS
    {
        //MAINSTATE_substate
        PLAY,
        QUIT,
        OPTION,
        MENU,
        LOBBY,
        WELCOME,
        NONE = -1
    };

    /**
    * @brief This class is the base class for all the bonus in the game
    */
    class Bouton : public IButton {
        public:

            /**
            * @brief Simple funtion to create a Button
            *
            * @param color Color of the shape of the button
            * @param text Text write for a button
            * @param pos Position of the button on the screen
            * @param size Size of the button
            */
            Bouton(sf::Color color, std::string text, sf::Vector2f pos, sf::Vector2f size) {
                this->text.setString(text);
                this->rShape.setFillColor(color);
                this->rShape.setSize(size); //base test is 200, 60
                this->rShape.setPosition(pos); // base pos is 440, 200
                type = NONE;
            };

            /**
            * @brief Constructor for class Button
            */
            Bouton() {};

            /**
            * @brief Destructor for class Button
            */
            ~Bouton() {};

            /**
            * @brief Function to check if coordinate is on a shape
            *
            * @param point Coordinate
            *
            * @return Return a Booleen
            */
            bool isPointInside(sf::Vector2f point) override
            {
                return this->rShape.getGlobalBounds().contains(point);
                // return this->rShape.getLocalBounds().contains(point);
            }

            /**
            * @brief Override draw
            *
            * @param w Windows to draw in
            */
            void Draw(rtype::engine::Window &w) override {
                w.Draw(this->rShape);
            };

            /**
            * @brief Set Position of an object
            *
            * @param nPos Position to objetc to go
            */
            void setPosition(sf::Vector2f nPos) {
                this->rShape.move(nPos);
            };

            // template <typename T, typename fpara>
            // bool execOnClick(fpara parameter, std::function<T(fpara)> func) {
            //     //update button appearance here
            //     return func(parameter);
            // };

            /**
            * @brief Override OnLeave
            *
            * @return Return a Booleen
            */
            bool OnLeave() override {
                return false;
            }

            /**
            * @brief Override OnClick
            *
            * @return Return a Booleen
            */
            bool OnClick() override {
                std::string s(this->text.getString().toAnsiString());
                std::cout<<s<<std::endl;
                return false;
            }

            /**
            * @brief Override OnHover
            */
            bool OnHover() override {
                //update button appearance here
                return false;
            };

            /**
            * @brief Get the type of the button
            *
            * @return Return the state of a button
            */
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
