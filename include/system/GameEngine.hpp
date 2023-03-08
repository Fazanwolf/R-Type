/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** GameEngine
*/

#pragma once

#include "system/gameStates/SGamePlay.hpp"
#include "gameStates/SMenu.hpp"
#include <Skaldi.hpp>
#include <queue>

#ifndef GAMEENGINE_HPP_
#define GAMEENGINE_HPP_

namespace rtype
{
    class GameEngine {
        public:
            GameEngine()
            {
                // game::SGamePlay gameplay;
                // states.push_back(&gameplay);
                // states.back()->init();
//                cursState.init();
//                win.CreateWindow({920, 620}, "R-Type");
            };

            void createWindow()
            {
                win.CreateWindow({920, 620}, "R-Type");
            }

            void init()
            {
                event = engine::Event(this->clt);
                std::string tmp = clt->client->getBuffer();
                if (!tmp.empty()) std::cout<<"PID ? "<<tmp<<std::endl;
                cursState.init(std::stoi(tmp));
            }

            ~GameEngine()
            {
            };

            /**
            * @brief Create a State object
            *
            * @param state
            * @return GameState* A state
            */
            GameState *createState(int state)
            {
                switch (state)
                {
                    case STATES::PLAY :
                        std::cout<<"PLAY"<<std::endl;
                        // this->init();
                        return new rtype::game::SGamePlay();
                        // isRunning = false;
                        // exit(0);
                        // break;
                    case STATES::QUIT :
                        std::cout<<"QUIT"<<std::endl;
                        setIsRunning(false);
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
                return new rtype::NULLState();
            }

            void update()
            {
                this->clt->client->receive();
                std::cout << this->clt->client->getBuffer() << std::endl;
                cursState.update();
                this->win.clear();
                // states.back()->update();
            };

            void draw()
            {
                // states.back()->draw(this->win);
                cursState.draw(this->win);
                this->win.DrawWindow();
            };

            /**
            * @brief Get the Is Running object
            *
            * @return true
            * @return false
            */
            bool getIsRunning() {return isRunning;}

            /**
             * @brief Set the Is Running object
             *
             * @param state
             */
            void setIsRunning(bool state) {
                isRunning = state;
            }

            /**
            * @brief Load a state
            *
            * @param new_state
            * @return true
            * @return false
            */
            bool loadState(GameState *new_state)
            {
                this->states.push(new_state);

                if (this->states.empty()) {return false;}

                if (this->states.size() > 1) { this->states.pop();}

                this->states.front()->init();

                // std::cout << this->states.front()->getName() << std::endl;

                setIsRunning(true);

                return true;
            };

            /**
            * @brief Run a state
            *
            * @param state
            */
            void runState(int state)
            {
                if (state != STATES::NONE) {
                    loadState(createState(state));
                }
                int swapState = STATES::NONE;
                while (this->isRunning && this->win.IsOpen()) {

                    if (states.empty()) {
                        return;
                    }

                    swapState = this->states.front()->handleEvent(win, event);
                    if (swapState == STATES::QUIT) {
                        setIsRunning(false);
                        this->win.close();
                        exit(0);
                    } else if (swapState != STATES::NONE) {
                        std::cout<<"runNew\n";
                        runState(swapState);
                    }

                    this->states.front()->update();
                    this->states.front()->draw(this->win);
                }
            }

            void handleEvent()
            {
                // this->clt.getInput();
                // std::string tmp = this->clt->client->getBuffer();
                // if (!tmp.empty()){
                //     std::cout<<"Cli Buffer : "<<tmp<<std::endl;
                //     this->server_updates.push(tmp);
                // }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    this->win.close();
                    exit(0);
                }
                if (this->cursState.getLocalPlayerID() == -1)
                    return;
                cursState.handleEvent(this->win, this->event);
            };

            engine::Window win;
            STATES gState;
            engine::Event event = nullptr;
            std::queue<std::string> server_updates;
            sk::Skaldi<sk::client::UDP, sk::server::UDP> *clt;

    protected:
        game::SGamePlay cursState;
        bool isRunning;
        std::queue<GameState*> states;
        // std::vector<GameState*> states; // level
    };
}

#endif /* !GAMEENGINE_HPP_ */