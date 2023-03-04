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

namespace rtype::game {

    class SGamePlay : public GameState {
        public:
            SGamePlay()
            {
                this->name = "GamePlay";
                isMatchRunning = false;
            };

            SGamePlay(int nb_players)
            {
                this->name = "GamePlay";
                isMatchRunning = false;
            };

            ~SGamePlay()
            {

            };

            void init() override
            {
                //init sprites;
                // for (int i = 0; i != 2; i++)
                this->EManager.NewEntity("./assets/ovni.png", {100, 100}, {0.1, 0.1});
                //FirstEntities
                // this->EManager.NewEntity("./assets/ovni.png", {600, 100}, {0.2, 0.2});
            };

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

            int8_t getLocalPlayerID() {return this->EManager.getPId();};

            int handleEvent(engine::Window &w, engine::Event &ev)
            {
                LocalInput(ev);
                return 0;
            };

            void draw(rtype::engine::Window &w) override
            {
                //draw entities
                w.clear();
                std::cout<<"draw"<<std::endl;
            };

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

#endif /* !SGAMEPLAY_HPP_ */