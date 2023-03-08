/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Audio
*/

#ifndef AUDIO_HPP_
#define AUDIO_HPP_

#include "Engine/Engine.hpp"

namespace rtype::components {

    /**
     * @brief This class is used to create a sound
     *
     */
    class Audio {
        public:
            Audio() {};
            ~Audio() {};
            /**
             * @brief This function is used to create a sound
             *
             * @param filename file path to the sound
             * @param volume volume of the sound
             * @param islooping set to true to make it infinite or false if you want a single time
             */
            void CreateSound(std::string filename, int volume, bool islooping) {
                if (!music.openFromFile(filename))
                    std::cout << "Error while loading the music" << std::endl;
                music.setVolume(volume);
                if (islooping == true) {
                    music.setLoop(islooping);
                    music.play();
                } else
                    music.play();
            }

        protected:
        private:
            sf::Music music;
    };
}

#endif /* !AUDIO_HPP_ */
