/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** main
*/

#include "Engine/Engine.hpp"
#include "Engine/Error.hpp"
#include "system/GameEngine.hpp"

int main(void)
{
    try {
        rtype::GameEngine g;

        g.init();
        g.runState(rtype::STATES::MENU);
        g.win.close();
    } catch (Error &error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}