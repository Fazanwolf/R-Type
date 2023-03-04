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

namespace rtype::game
{

class SMenu : public GameState {

    public: //data declared here are suggested to behave differently in the next patch due to ECS updates
        std::vector<rtype::components::Bouton> btns;
        std::vector<sf::Texture> textures;

    public:
        std::string getName(){
            return name;
        }

        SMenu() {
            this->name = "Menu";
        };

        ~SMenu() {};

        void init() override {
            //init Textures
            //init standard textureless buttons;
            sf::Vector2f pos({460-100, 200});
            btns.push_back(components::Bouton(sf::Color::Green, "PLAY", pos, {200,60}));
            btns.push_back(components::Bouton(sf::Color::Red, "QUIT", {pos.x, pos.y + 120}, {200,60}));
        
            return;
        }

        void update() override {return;}

        int handleEvent(rtype::engine::Window &w, engine::Event &ev) override {
            w;            
            sf::Event ed;
            ev.GetMousePos(ed);

            //click handler
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition();
                for (auto &btn : btns) {
                    if (btn.isPointInside({mousePos.x, mousePos.y}) )
                    {
                        switch (btn.getType())
                        {
                            case components::PLAY :
                                break;
                            case components::QUIT :
                                break;
                            case components::OPTION :
                                break;
                            case components::WELCOME :
                                break;
                            case components::MENU :
                                break;
                            case components::LOBBY :
                                break;
                        default:
                            break;
                        }
                    }
                }


            }
            //Keyboard handler
            return components::NONE;
        };

        int handleEvent(rtype::GameEngine *g) override {
            //click handler
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition();
                for (auto &btn : btns) {
                    if (btn.isPointInside({mousePos.x, mousePos.y}) && btn.getType() != components::STATEBUTTONS::NONE)
                        return btn.getType();
                }
            }
            //Keyboard handler
            return components::NONE;
        };

        void draw(rtype::engine::Window &w) override
        {
            w.clear();
            // this->EManager.Draw();
            for (auto btn: btns) { btn.Draw(w);}
            w.getWindow().display();
        };

    protected:
        std::string name;
};
}
#endif /* !SMENU_HPP_ */
