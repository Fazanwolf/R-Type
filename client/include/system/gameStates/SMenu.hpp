/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Stest
*/

#pragma once

#ifndef SMENU_HPP_
#define SMENU_HPP_


#include "IGameState.hpp"
#include "Components/Bouton.hpp"

using namespace rtype;
/**
 * @brief The namespace of the SMenu in game
 * 
 */
namespace rtype::game
{
/**
 * @brief The class of the SMenu in game
 * 
 */
class SMenu : public GameState {
    
    public: //data declared here are suggested to behave differently in the next patch due to ECS updates
        std::vector<rtype::components::Bouton> btns;
        std::vector<sf::Texture> textures;

    public:
        /**
         * @brief Get the Name object
         * 
         * @return std::string 
         */
        std::string getName(){
            return name;
        }
        /**
         * @brief Construct a new SMenu object
         * 
         */
        SMenu() {
            std::cout<<"MENU PLAYING HERE\n";
            this->name = "Menu";
        };
        /**
         * @brief Destroy the SMenu object
         * 
         */
        ~SMenu() {};

        /**
         * @brief Init the menu
         * 
         */
        void init() override {
            //init Textures
            //init standard textureless buttons;
            std::cout<<"INIT PLAYING HERE\n";
            sf::Vector2f pos({460-100, 200});
            btns.push_back(components::Bouton(sf::Color::Green, "PLAY", pos, {200,60}));
            btns.push_back(components::Bouton(sf::Color::Red, "QUIT", {pos.x, pos.y + 120}, {200,60}));
        
            return;
        }
    
        /**
         * @brief Update the menu
         * 
         */
        void update(/*rtype::engine::Window &w*/) override {return;}

        /**
         * @brief Handle the events of the menu
         * 
         * @param w 
         * @param ev 
         * @return int 
         */
        int handleEvent(rtype::engine::Window &w, engine::Event &ev) override {
           if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                std::cout<<"Mouse Pressed"<<std::endl;
                sf::Vector2i mousePos = sf::Mouse::getPosition(w.getWindow());
                for (auto &btn : btns) {
                    std::cout<< "Point Inside ? "<< ( btn.isPointInside(w.getWindow().mapPixelToCoords(mousePos)) == true ? "true":"false") <<std::endl;
                    if (btn.isPointInside({mousePos.x, mousePos.y}) == true
                            && btn.getType() != components::STATEBUTTONS::NONE) {
                        btn.OnClick();
                        return btn.getType();
                    }
                }
            }
            // //Keyboard handler
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                return components::QUIT;
            return components::NONE;
        };

        /**
         * @brief Handle the events of the menu
         * 
         * @param g the state
         * @return int 
         */
        int handleEvent(rtype::GameEngine *g) override {
            //click handler
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                std::cout<<"Mouse Pressed"<<std::endl;
                sf::Vector2i mousePos = sf::Mouse::getPosition();
                for (auto &btn : btns) {
                    // std::cout<< "Point Inside ? "<< ( btn.isPointInside(g->win.getWindow().mapPixelToCoords(mousePos)) == true ? "true":"false") <<std::endl;
                    // if (btn.isPointInside({mousePos.x, mousePos.y}) == true)
                        // btn.OnClick();
                     //&& btn.getType() != components::STATEBUTTONS::NONE)
                        // return btn.getType();
                }
            }
            // //Keyboard handler
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                return components::QUIT;
            return components::NONE;
        };

        /**
         * @brief Draw the menu
         * 
         * @param w 
         */
        void draw(rtype::engine::Window &w) override
        {
            w.clear();
            // this->EManager.Draw();
            for (auto btn: btns) { btn.Draw(w.getWindow());}
            w.getWindow().display();
        };

    protected:
        std::string name;
};
}
#endif /* !SMENU_HPP_ */
