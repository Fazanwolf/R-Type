/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "Engine/Engine.hpp"

namespace rtype::engine {

    class Window {
        public:
            Window();
            ~Window();
            int DisplayWindow(void);
            int DrawWindow(void) {this->window.display(); return 0;};
            bool UpdateEvent(void);
            bool IsOpen(void);
            bool IsClosed(void);
            bool HandleEvent(const sf::Event::EventType &type);
            void CreateWindow(sf::VideoMode mode, std::string name);

            void clear() { this->window.clear(sf::Color::Black); };
            void close() {this->window.close();};

            void t_clock()
            {
                this->winTimer = this->winClock.getElapsedTime();
                std::cerr<<winTimer.asSeconds()<<std::endl;
                if (this->winTimer.asSeconds() > 1.f)
                    winClock.restart();
            };

            void Draw(sf::Drawable &en)
            {
                this->window.draw(en);
            }

            sf::RenderWindow &getWindow() {
                return this->window;
            }

        protected:
        private:
            std::string window_name;
            sf::VideoMode window_mode;
            sf::Event window_event;
            sf::RenderWindow window;
            sf::Clock winClock;
            sf::Time winTimer;

    };
}

#endif /* !WINDOW_HPP_ */
