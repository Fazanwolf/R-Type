/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** IGameState
*/

#pragma once

#include "IGameState.hpp"
#include <queue>
#include <string>
#include <cstring>
#include <Skaldi.hpp>

#ifndef SGAMEPLAY_HPP_
#define SGAMEPLAY_HPP_

using namespace rtype;
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
            /**
             * @brief Init the game state
             * 
             */
            void init() override
            {
                //init sprites;
                // for (int i = 0; i != 2; i++)
                this->EManager.NewEntity("./assets/ovni.png", {100, 100}, {0.1, 0.1});
                //FirstEntities
                // this->EManager.NewEntity("./assets/ovni.png", {600, 100}, {0.2, 0.2});
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
                LocalInput(ev);
                return 0;
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
                for (auto& e : this->EManager.getIDs())
                    w.Draw(this->EManager.getSprite(e));
                w.getWindow().display();
                std::cout<<"draw"<<std::endl;
            };
            /**
             * @brief check a input
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
                    return 1;
                    // return rtype::STATES::QUIT;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    //fire system
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) /*|| ready button pressed*/) {
                    //send ready  info
                }

                ev.MakeSpriteMovable(this->EManager.getSprite(0));
            }

        private:
            bool isMatchRunning; //when all player are ready set to true

    };

}

#endif /* !SGAMEPLAY_HPP_ */