/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** main
*/

#include "../include/Engine/Engine.hpp"
#include "../include/Engine/Error.hpp"
#include "../include/system/gameStates/SGamePlay.hpp"
#include "../include/system/GameEngine.hpp"

int main(void)
{
    try {
        // rtype::engine::StateManager state;
        // rtype::engine::Window win;
        rtype::GameEngine g;

        // state.GameRun();
        // while (win.IsOpen()) {
        //     win.UpdateEvent();
        // }
        // state.GameRun();
        while (g.win.IsOpen())
        {
            g.handleEvent();
            g.update();
            g.draw();
        }
    }
    catch (Error &error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}