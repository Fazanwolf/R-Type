/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Audio
*/

#ifndef AUDIO_HPP_
#define AUDIO_HPP_

#include "Engine.hpp"

namespace rtype::engine {

    class Audio {
        public:
            Audio();
            ~Audio();
            void CreateSound(sf::Sound audio);

        protected:
        private:
            sf::Sound a_sound;
    };
}

#endif /* !AUDIO_HPP_ */
