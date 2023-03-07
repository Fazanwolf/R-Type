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
             * @return int8_t of the pid
             */
            int8_t getLocalPlayerID() {return this->EManager.getPId();};
            /**
             * @brief Handle the event
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
             * @brief Draw the game state
             * 
             * @param w 
             */
            void draw(rtype::engine::Window &w) override
            {
                //draw entities
                w.clear();
                std::cout<<"draw"<<std::endl;
            };
            /**
             * @brief Get the Input
             * 
             * @return Return a int
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

                ev.MakeSpriteMovable(this->EManager.getSprite(0));
            }

        private:
            bool isMatchRunning; //when all player are ready set to true

    };

}
