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

    /**
     * @brief This function is if the object is an instance of the class
     * 
     * @tparam Base 
     * @tparam T 
     * @param ptr 
     * @return true 
     * @return false 
     */
    template<typename Base, typename T>
    inline bool instanceof(const T *ptr) {
        return dynamic_cast<const Base*>(ptr) != nullptr;
    }
    /**
     * @brief The class of the GameEngine
     * 
     */
    class GameEngine {
    public:
        /**
         * @brief Construct a new Game Engine object
         * 
         */
        GameEngine()
        {
        };
        /**
         * @brief Destroy the Game Engine object
         * 
         */
        ~GameEngine()
        {
        };
        /**
         * @brief Init the game engine
         * 
         */
        void init()
        {
            win.nWindow({920, 620}, "R-Type");
            // event = engine::Event(this->clt);
            //std::string tmp = clt->client->getBuffer();
            //if (!tmp.empty()) std::cout<<"PID ? "<<tmp<<std::endl;
        }
        //done
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
            std::cout << "START loadstate" << std::endl;

            if (this->states.empty()) {return false;}

            if (this->states.size() > 1) { this->states.pop();}
            
            this->states.front()->init();

            // std::cout << this->states.front()->getName() << std::endl;

            setIsRunning(true);

            std::cout << "END loadstate" << std::endl;
            return true;
        };
        // void runState(GameState *state)
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
            std::cout << "POST loadstate" << std::endl;
            int swapState = STATES::NONE;
            while (this->isRunning && this->win.IsOpen()) {

                if (states.empty()) {
                    return;
                }
                // std::cout << "1" << std::endl;

                swapState = this->states.front()->handleEvent(win, event);
                // std::cout << "2" << std::endl;
                // swapState = this->states.front()->handleEvent(this);
                std::cout<<swapState<<std::endl;
                if (swapState == STATES::QUIT) {
                    setIsRunning(false);
                } else if (swapState != STATES::NONE) {
                    std::cout<<"runNew\n";
                    runState(swapState);
                }

                this->states.front()->update();
                this->states.front()->draw(this->win);
                // std::cout << "3" << std::endl;
            }
        }
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