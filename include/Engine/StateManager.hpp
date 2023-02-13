/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** StateManager
*/

#ifndef STATEMANAGER_HPP_
#define STATEMANAGER_HPP_

#include "Engine/Engine.hpp"
#include "Engine/Window.hpp"

namespace rtype::engine {
    enum StateManage {
        MENU,
        END,
        GAME,
    };

    class StateManager {
        public:
            StateManager();
            ~StateManager();
            /**
             * @brief Create a menu
             *
             */
            void Menu(void);
            /**
             * @brief Launch the game
             *
             */
            void GameRun(void);
            /**
             * @brief Init an end game
             *
             */
            void End(void);

        protected:
        private:
    };
}

#endif /* !STATEMANAGER_HPP_ */
