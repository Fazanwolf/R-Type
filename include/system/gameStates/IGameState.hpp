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
/**
 * @brief The namespace of the game
 * 
 */
namespace rtype
{

/**
 * @brief enum of the states
 * 
 */
enum STATES
{
    PLAY,
    QUIT, 
    OPTION,
    MENU,
    LOBBY,
    WELCOME,
    NONE = -1
};

class GameEngine;
/**
 * @brief The class of the game state
 * 
 */
class IGameState {
    public:
        /**
         * @brief Init the game state
         * 
         */
        virtual void init() = 0;
        /**
         * @brief Update the game state
         * 
         */
        virtual void update() = 0;
        // virtual void clear() = 0;
        // virtual void pause() = 0;
        // virtual void resume() = 0;
        /**
         * @brief Get the Name object
         * 
         * @param w 
         * @param ev 
         * @return int 
         */
        virtual int handleEvent(rtype::engine::Window &w,  engine::Event &ev) = 0;
        /**
         * @brief Handle the event
         * 
         * @param g the game state
         * @return int 
         */
        virtual int handleEvent(rtype::GameEngine *g) = 0;
        /**
         * @brief Draw the game state
         * 
         * @param w 
         */
        virtual void draw(rtype::engine::Window &w) = 0;

    protected:
        entities::EntitiesManager EManager;

};
/**
 * @brief The class of the game state
 * 
 */
class GameState : public IGameState {
    public:
        /**
         * @brief Get the Name object
         * 
         * @return std::string 
         */
        std::string getName(){
            return name;
        }
        /**
         * @brief Construct a new Game State object
         * 
         */
        GameState() {};
        /**
         * @brief Destroy the Game State object
         * 
         */
        ~GameState() {};
        /**
         * @brief Init the game state
         * 
         */
        void init() override { return;}
        /**
         * @brief Update the game state
         * 
         */
        void update() override {return;}
        /**
         * @brief Handle the event
         * 
         * @param g 
         * @return int 
         */
        int handleEvent(rtype::GameEngine *g) override { g; return -1; };
        /**
         * @brief Handle the event
         * 
         * @param w 
         * @param ev 
         * @return int 
         */
        int handleEvent(rtype::engine::Window &w,  engine::Event &ev) override {
            w;
            sf::Event ed;
            ev.GetMousePos(ed);
            return -1;
        };
        /**
         * @brief Draw the game state
         * 
         * @param w 
         */
        void draw(rtype::engine::Window &w) override
        {
            w;
        };

    protected:
        std::string name;
};
/**
 * @brief The class NULLState of the game state
 * 
 */
class NULLState : public GameState
{
    public:
        /**
         * @brief Construct a new NULLState object
         * 
         */
        NULLState() {};
        /**
         * @brief Destroy the NULLState object
         * 
         */
        ~NULLState() {};
};

}

#endif /* !IGAMESTATE_HPP_ */