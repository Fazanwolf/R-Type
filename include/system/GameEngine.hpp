/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** GameEngine
*/

#pragma once

#include "system/gameStates/SGamePlay.hpp"
#include "system/gameStates/SMenu.hpp"
// #include <Skaldi.hpp>
#include <queue>
#ifndef GAMEENGINE_HPP_
#define GAMEENGINE_HPP_

namespace rtype
{
    enum STATES
    {
        PLAY,
        LOBBY,
        MENU,
        QUIT,
        NONE
    };

    class GameEngine {
        public:
            GameEngine()
            {
            };

            ~GameEngine()
            {
            };

            void init()
            {
                win.CreateWindow({920, 620}, "R-Type");
                // event = engine::Event(this->clt);
                //std::string tmp = clt->client->getBuffer();
                //if (!tmp.empty()) std::cout<<"PID ? "<<tmp<<std::endl;
            }

            //done
            bool loadState(GameState *new_state)
            {
                this->states.push(new_state);
                        std::cout << "loadstate" << std::endl;
                if (this->states.empty()) {
                    std::cout << "Hello Again !\n";
                    return false;
                    }
                if (this->states.size() > 1)
                    this->states.pop();
                else {
                    this->states.front()->init();
                    std::cout << this->states.front()->getName() << std::endl;
                }
                this->isRunning = true;

                        std::cout << "isrunning" << std::endl;
                return true;
            };

            void runState(GameState *state)
            {
                        std::cout << "456" << std::endl;
                loadState(state);
                
                while (this->isRunning && this->win.IsOpen()) {
                        std::cout << "while" << std::endl;
                    if (states.empty()) {
                        std::cout << "4564" << std::endl;
                        return;
                    }
                    this->states.front()->handleEvent(win, event);
                    this->states.front()->update();
                    // std::cout << "2" << std::endl;
                    this->states.front()->draw(this->win);
                    // std::cout << "3" << std::endl;
                }
            }

            engine::Window win;
            STATES gState;
            engine::Event event = nullptr;
            std::queue<std::string> server_updates;
            // sk::Skaldi<sk::client::UDP, sk::server::UDP> *clt;
            
    protected:
        bool isRunning;
        std::queue<GameState*> states;
    };
}

#endif /* !GAMEENGINE_HPP_ */