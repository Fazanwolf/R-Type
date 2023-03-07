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
                if (!textures[0].loadFromFile("./assets/ovni.png"))
                    std::cout << "error" << std::endl;
            }

            /**
             * @brief Init the game state
             * 
             */
            void init() override
            {
                std::cout<<"Init Gameplay"<<std::endl;

                // this->clt->connect("?");
                loadGameTexture();
                //init sprites;
                // this->MapManager.initMap(); // add a map
                this->EManager.NewEntity("./assets/ovni.png", {20, 30}, {0.2, 0.2});
                // this->CManager.Centipedeinit(300, 600, 50); // add a centipede
                this->BManager.initBackground("./assets/Nebula_Aqua-Pink.png", {1.5, 1.5});
                this->EManager.NewEntity("./assets/spaceship.png", {20, 300}, {0.3, 0.3});
                // this->EManager.NewEntity(textures[0], {20, 300}, {1.5, 1.5});
            };

            /**
             * @brief Update the game state
             * 
             */
            void update() override
            {
                if (!isMatchRunning) {
                    //update button appearance etc
                    //update Status
                }
                // this->MapManager.update(); // add a map
                // this->CManager.update(); // add centipede
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
            int handleEvent(engine::Window &w, engine::Event &ev)
            {
                int resLocalInput = LocalInput(ev);
                // std::cout<<"handleEvent"<<std::endl;
                this->EManager.handleEvent(ev);
                return resLocalInput;
                // return (resLocalInput == -1 ? resLocalInput:rtype::STATES::NONE : resLocalInput);
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
                this->BManager.draw(w.getWindow());
                this->EManager.draw(w.getWindow());
                // this->MapManager.render(w.getWindow()); // add a map
                // this->CManager.draw(w.getWindow()); // add a centipede
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
                // ev.MakeSpriteMovable(this->EManager.getSprite(0));
                return -1;
            }
            sk::Client<sk::client::UDP> *clt;

        private:
            sf::Sprite shape;
            bool isMatchRunning; //when all player are ready set to true
            std::array<sf::Texture, 100> textures;
    };

}

#endif /* !SGAMEPLAY_HPP_ */