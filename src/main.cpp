/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** main
*/

#include "../include/Engine/Engine.hpp"
#include "../include/Engine/Error.hpp"

int main(void)
{
    try {
        StateManager state;
    }
    catch (Error &error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}