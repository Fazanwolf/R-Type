/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** GameEngine
*/

#pragma once

#include "system/gameStates/SGamePlay.hpp"
#include <Skaldi.hpp>

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
                cursState.init();
                event = engine::Event(this->clt);
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

            void handleEvent()
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    this->win.close();
                cursState.handleEvent(this->win, this->event);
                // if (!states.empty())
                //     states.back()->handleEvent(this->win, this->ev);
            };

            engine::Window win;
            STATES gState;
            engine::Event event = nullptr;
            sk::Skaldi<sk::client::UDP, sk::server::UDP> *clt;

    protected:
        game::SGamePlay cursState;
        // std::vector<GameState*> states; // level
    };
}

#endif /* !GAMEENGINE_HPP_ */