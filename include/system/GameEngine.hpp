/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** GameEngine
*/

#pragma once

#include "system/gameStates/SGamePlay.hpp"
#include <Skaldi.hpp>
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

            void loadState(GameState new_state)
            {
                // if (!states.empty()) {
                //     states.pop_back();
                // }
                // states.push_back(&new_state);
                // states.back()->init();
            };

            void update()
            {
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
        // std::vector<GameState*> states; // level
    };
}

#endif /* !GAMEENGINE_HPP_ */