/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** StateManager
*/

#include "../include/Engine/StateManager.hpp"
#include "../include/system/GameEngine.hpp"

using namespace rtype::engine;

StateManager::StateManager()
{
    // window.DisplayWindow();
}

StateManager::~StateManager()
{
}

void StateManager::GameRun()
{
    rtype::GameEngine g;

    g.win.CreateWindow({920, 620}, "R-Type");
}

// StateManager::Pause()
// {

// }

void StateManager::Menu()
{

}

void StateManager::End()
{

}