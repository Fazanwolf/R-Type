/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Destroy
*/

#pragma once

#include "Engine/Engine.hpp"

namespace rtype::engine {

    class Destroy {
        public:
            Destroy();
            ~Destroy();
            void DestroyWindow(sf::RenderWindow win);
            void DestroyAssets(sf::Texture texture);
            void DestroyAudio(sf::Sound audio);

        protected:
        private:
    };
}
