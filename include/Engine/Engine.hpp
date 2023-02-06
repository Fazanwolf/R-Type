/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Engine
*/

#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <vector>
#include <stdbool.h>
#include <stdlib.h>
#include <exception>
#include "Window.hpp"
#include "Draw.hpp"
#include "Event.hpp"
#include "StateManager.hpp"
#include "EntitiesManager.hpp"
#include "Bullets.hpp"

class Engine {
    public:
        Engine();
        ~Engine();

    protected:
    private:
};

#endif /* !Engine_HPP_ */
