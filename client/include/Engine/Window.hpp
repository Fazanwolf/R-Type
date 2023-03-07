/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Window
*/

#pragma once

//SCREEN SIZE
#define WINDOWED_SMALL sf::Vector2f(920,420)
#define WINDOWED sf::Vector2f(0,0)
#define WINDOWED_BIG sf::Vector2f(0,0)
#define FULLSCREEN sf::Vector2f(1920,1080)

#include "Engine/Engine.hpp"


/**
* @brief This namespace is for herite from engine
*/
namespace rtype::engine {

    /**
    * @brief This class is the base class for all the Window
    */
    class Window {
        public:

            /**
            * @brief Constructor for class Window
            */
            Window();

            /**
            * @brief Destructor for class Window
            */
            ~Window();

            /**
            * @brief Function to Display a window
            *
            * @return Return 0 when end
            */
            int DisplayWindow(void);

            /**
            * @brief Function to Draw a window
            *
            * @return Return 0 when end
            */
            int DrawWindow(void) {this->window.display(); return 0;};

            /**
            * @brief Function to update the event in the window
            *
            * @return Return a Boolean
            */
            bool UpdateEvent(void);

            /**
            * @brief Function to check if the window is open
            *
            * @return Return true if the window is open and false if not
            */
            bool IsOpen(void);

            /**
            * @brief Function to check if the window is open
            *
            * @return Return true if the window is close and false if not
            */
            bool IsClosed(void);

            /**
            * @brief Function to handle event
            *
            * @param type Event Type
            *
            * @return Return a Boolean
            */
            bool HandleEvent(const sf::Event::EventType &type);

            /**
            * @brief Function to create a window
            *
            * @param mode Video mode of the window
            * @param name Name of the window
            */
            void nWindow(sf::VideoMode mode, std::string name);


            /**
            * @brief Function to clear a window
            */
            void clear() { this->window.clear(sf::Color::Black); };

            /**
            * @brief Function to close a window
            */
            void close() {this->window.close();};

            /**
            * @brief Function to render a window
            *
            * @return Return a window
            */
            sf::RenderWindow &getWindow() {
                return this->window;
            }

            /**
            * @brief Simple clock for the window
            */
            void t_clock()
            {
                this->winTimer = this->winClock.getElapsedTime();
                std::cerr<<winTimer.asSeconds()<<std::endl;
                if (this->winTimer.asSeconds() > 1.f)
                    winClock.restart();
            };

            /**
            * @brief Function to draw on the windows
            *
            * @param en Something to draw on the window
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
