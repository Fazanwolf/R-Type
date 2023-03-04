/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** GameEngine
*/

#pragma once

#include "gameStates/States.hpp"

// #include <Skaldi.hpp>
#include <queue>
#ifndef GAMEENGINE_HPP_
#define GAMEENGINE_HPP_

namespace rtype
{
    enum STATES
    {
        PLAY,
        QUIT, 
        OPTION,
        MENU,
        LOBBY,
        WELCOME,
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

        GameState *createState(int state)
        {
            switch (state)
            {
                case STATES::PLAY :
                    std::cout<<"PLAY"<<std::endl;
                    isRunning = false;
                    break;
                    // return new GameState();
                case STATES::QUIT :
                    std::cout<<"QUIT"<<std::endl;
                    isRunning = false;
                    break;
                case STATES::OPTION :
                    break;
                case STATES::WELCOME :
                    break;
                case STATES::MENU :
                    std::cout<<"MENU"<<std::endl;
                    return new rtype::game::SMenu();
                case STATES::LOBBY :
                    break;
            default:
                break;
            }
        }

        bool loadState(GameState *new_state)
        {
            this->states.push(new_state);
            std::cout << "loadstate" << std::endl;
            if (this->states.empty()) {
                return false;
                }
            if (this->states.size() > 1)
                this->states.pop();
            else {
                this->states.front()->init();
                std::cout << this->states.front()->getName() << std::endl;
            }
            this->isRunning = true;
            return true;
        };
        // void runState(GameState *state)
        void runState(int state)
        {
            if (state != STATES::NONE) {
                loadState(createState(state));
            }
            
            while (this->isRunning && this->win.IsOpen()) {
                if (states.empty()) {
                    return;
                }
                // this->states.front()->handleEvent(win, event);
                auto swapState = this->states.front()->handleEvent(this);
                std::cout<<swapState<<std::endl;
                if (swapState != STATES::NONE) {
                    std::cout<<"runNew\n";
                    runState(swapState);
                }
                this->states.front()->update();
                // std::cout << "2" << std::endl;
                this->states.front()->draw(this->win);
                // std::cout << "3" << std::endl;
            }
        }

        bool getIsRunning() {return isRunning;}
        void setIsRunning(bool state) {isRunning = state;}

        engine::Window win;
        // STATES gState;
        engine::Event event = nullptr;
        std::queue<std::string> server_updates;
        // sk::Skaldi<sk::client::UDP, sk::server::UDP> *clt;
            
    protected:
        bool isRunning;
        // GameEngine self() {return *this};
        std::queue<GameState*> states;
    };
}

#endif /* !GAMEENGINE_HPP_ */