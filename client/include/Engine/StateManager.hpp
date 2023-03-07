/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** StateManager
*/

#pragma once
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
            void Menu(void);
            void GameRun(void);
            void End(void);

        protected:
        private:
    };
}
