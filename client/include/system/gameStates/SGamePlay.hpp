/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** IGameState
*/

#pragma once

#include "IGameState.hpp"
#include <queue>
#include <array>
#include <string>
#include <cstring>
#include <Skaldi.hpp>

#ifndef SGAMEPLAY_HPP_
#define SGAMEPLAY_HPP_

using namespace rtype;
using namespace rtype::components;
/**
 * @brief The namespace of the SGamePlay
 * 
 */
namespace rtype::game {
    /**
     * @brief The class of the SGamePlay
     * 
     */
    class SGamePlay : public GameState {
        public:
            /**
             * @brief Construct a new SGamePlay object
             * 
             */
            SGamePlay()
            {
                this->name = "GamePlay";
                isMatchRunning = false;
            };

            /**
             * @brief Construct a new SGamePlay object
             * 
             * @param nb_players 
             */
            SGamePlay(int nb_players)
            {
                this->name = "GamePlay";
                isMatchRunning = false;
            };

            /**
             * @brief Destroy the SGamePlay object
             * 
             */
            ~SGamePlay()
            {

            };

            void loadGameTexture(std::vector<std::string> paths)
            {
                int i = 0;
                for (auto p : paths) {
                    if (!textures[i++].loadFromFile(p))
                        std::cout << "error" << std::endl;
                }

            }

            void loadGameTexture(void)
            {

                std::cout << "loading...Ovni" << std::endl;
                if (!textures[0].loadFromFile("./assets/ovni.png")) {
                    std::cerr << "error" << std::endl;
                    exit(84);
                }
            }

            /**
             * @brief Init the game state
             * 
             */
            void init() override
            {
                std::cout<<"Init Gameplay"<<std::endl;

                // loadGameTexture();
                //init sprites;
                // this->shape.setFillColor(sf::Color::Green);
                this->shape.setScale( {1.5,1.5} );
                this->shape.setPosition( {20,30} );
                this->shape.setTexture(textures[0]);
                std::cout<<"Failed before ovni?\n";
                this->EManager.NewEntity("./assets/ovni.png", {20, 30}, {0.5, 0.5} );
                std::cout<<"Failed after ovni?\n";
                // this->EManager.NewEntity(textures[0], {20, 30}, {0.5, 0.5});
            };

            /**
             * @brief Update the game state
             * @param w window to ref
             * 
             */
            void update(/*rtype::engine::Window &w*/) override
            {
                if (!isMatchRunning) {
                    //update button appearance etc
                    //update Status
                }
                std::cout<<"Failed ?\n";
                // this->EManager.update(w.getWindow());
                //update match data & physics
                // update client to server data
                //pop event queue here after rework
            };

            /**
             * @brief Get the Local Player I D object
             * 
             * @return int8_t 
             */
            int8_t getLocalPlayerID() {return this->EManager.getPId();};

            /**
             * @brief Handle the event input
             * 
             * @param w
             * @param ev
             * @return int 
             */
            int handleEvent(engine::Window &win, engine::Event &ev)
            {
                int resLocalInput = LocalInput(ev);
                // std::cout<<"handleEvent"<<std::endl;
                this->EManager.handleEvent(ev);
                return (resLocalInput != -1 ? resLocalInput:rtype::STATES::NONE);
            };

            /**
             * @brief Draw on the window
             * 
             * @param g the window
             * @return int 
             */
            void draw(rtype::engine::Window &w) override
            {

                //draw entities
                w.clear();
                this->EManager.draw(w.getWindow() );
                // w.getWindow().draw(this->shape);
                //     w.Draw(this->EManager.getSprite(e));
                w.getWindow().display();
                // std::cout<<"draw"<<std::endl;
            };

            /**
             * @brief check Local Player input
             * 
             * @param ev
             * @return int 
             */
            //State Property
            int LocalInput(engine::Event &ev) //returns -1 if nothing to return
            {
                //keyboard Input
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    return STATES::QUIT;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    //fire system
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) /*|| ready button pressed*/) {
                    //send ready  info
                }
                // ev.MakeObjectMovable(this->EManager.getLocalPlayer());
                return -1;
            }

        private:
            // sf::RenderWindow w;
            sf::Sprite shape;
            bool isMatchRunning; //when all player are ready set to true
            std::array<sf::Texture, 100> textures;
    };

}

#endif /* !SGAMEPLAY_HPP_ */