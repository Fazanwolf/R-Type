/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Destroy
*/

#ifndef DESTROY_HPP_
#define DESTROY_HPP_

#include "Engine.hpp"

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

#endif /* !DESTROY_HPP_ */
