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
            /**
             * @brief Display the window with his event
             *
             * @return int
             */
            int DisplayWindow(void);
            /**
             * @brief Draw the window
             *
             * @return int
             */
            int DrawWindow(void) {this->window.display(); return 0;};
            /**
             * @brief Use it to update the event
             *
             * @return true
             * @return false
             */
            bool UpdateEvent(void);
            /**
             * @brief Check if the window is open
             *
             * @return true
             * @return false
             */
            bool IsOpen(void);
            /**
             * @brief Check if the window is close
             *
             * @return true
             * @return false
             */
            bool IsClosed(void);
            /**
             * @brief Check the event type
             *
             * @return true
             * @return false
             */
            bool HandleEvent(const sf::Event::EventType &type);
            /**
             * @brief Create a Window object
             *
             * @param mode
             * @param name
             */
            void CreateWindow(sf::VideoMode mode, std::string name);
            /**
             * @brief Clear the window
             *
             */
            void clear() { this->window.clear(sf::Color::Black); };
            /**
             * @brief Close the window
             *
             */
            void close() {this->window.close();};

            /**
             * @brief Init the clock for the game
             *
             */
            void t_clock()
            {
                this->winTimer = this->winClock.getElapsedTime();
                std::cerr<<winTimer.asSeconds()<<std::endl;
                if (this->winTimer.asSeconds() > 1.f)
                    winClock.restart();
            };
            /**
             * @brief Draw the entity
             *
             * @param en
             */
            void Draw(sf::Drawable &en)
            {
                this->window.draw(en);
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
