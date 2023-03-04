/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** IGameState
*/

#pragma once

#include "Entities/EntitiesManager.hpp"
#include "Utils/String.hpp"
#include "system/GameEngine.hpp"


#ifndef IGAMESTATE_HPP_
#define IGAMESTATE_HPP_

class GameEngine;

namespace rtype
{

class GameEngine;

class IGameState {
    public:
        virtual void init() = 0;
        virtual void update() = 0;
        // virtual void clear() = 0;
        // virtual void pause() = 0;
        // virtual void resume() = 0;
        virtual int handleEvent(rtype::engine::Window &w,  engine::Event &ev) = 0;
        virtual int handleEvent(rtype::GameEngine *g) = 0;
        virtual void draw(rtype::engine::Window &w) = 0;

    protected:
        entities::EntitiesManager EManager;

};

class GameState : public IGameState {
    public:
        std::string getName(){
            return name;
        }
        GameState() {};
        ~GameState() {};
        void init() override { return;}
        void update() override {return;}

        int handleEvent(rtype::GameEngine *g) override { g; return -1; };

        int handleEvent(rtype::engine::Window &w,  engine::Event &ev) override {
            w;
            sf::Event ed;
            ev.GetMousePos(ed);
            return 0;
        };
        void draw(rtype::engine::Window &w) override
        {
            w;
        };
    protected:
        std::string name;
};

class NULLState : public GameState
{
    public:
        NULLState() {};
        ~NULLState() {};
};

}

#endif /* !IGAMESTATE_HPP_ */