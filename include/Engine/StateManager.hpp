/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** StateManager
*/

#ifndef STATEMANAGER_HPP_
#define STATEMANAGER_HPP_

#include "Engine.hpp"

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

#endif /* !STATEMANAGER_HPP_ */
