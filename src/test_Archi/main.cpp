/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main
*/

#include "Engine/Engine.hpp"
#include "Engine/Error.hpp"
#include "system/gameStates/SGamePlay.hpp"
#include "system/GameEngine.hpp"

int main(void)
{
    try {
        rtype::GameEngine game;
        game.createWindow();
        // game.init();
        game.CreateEntitie("mario.png", {500, 100}, {0.1, 0.1});
        while (game.win.IsOpen()) {
            game.handleEvent();
            game.update();
            game.draw();
        }
    } catch (Error &error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}
