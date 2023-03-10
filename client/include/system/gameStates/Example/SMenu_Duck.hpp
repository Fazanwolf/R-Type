/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Stest
*/

#pragma once

#include "IGameState.hpp"
#include "Components/Bouton.hpp"

using namespace rtype;
/**
 * @brief The namespace of the game
 * 
 */
namespace rtype::game {
    /**
     * @brief The class of the game state
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
                this->name = "Menu";
            };
            /**
             * @brief Destroy the SMenu object
             *
             */
            ~SMenu() {};
            /**
             * @brief Init the game state
             *
             */
            void init() override {
                //init Textures
                //init standard textureless buttons;
                sf::Vector2f pos({460-100, 200});
                btns.push_back(components::Bouton(sf::Color::Green, "PLAY", pos, {200,60}));
                btns.push_back(components::Bouton(sf::Color::Red, "QUIT", {pos.x, pos.y + 120}, {200,60}));

                return;
            }
            /**
             * @brief Update the game state
             *
             */
            void update() override {return;}
            /**
             * @brief handle input events
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
             * @brief handle input events
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
             * @brief Draw the game state
             *
             * @param w
             */
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
