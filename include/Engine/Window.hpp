/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "Engine.hpp"

class Window {
    public:
        Window();
        ~Window();
        int DisplayWindow(void);
        bool UpdateEvent(void);
        bool IsOpen(void);
        bool IsClosed(void);
        bool HandleEvent(const sf::Event::EventType &type);
        void CreateWindow(sf::VideoMode mode, std::string name);

    protected:
    private:
        std::string window_name;
        sf::VideoMode window_mode;
        sf::Event window_event;
        sf::RenderWindow window;
};

#endif /* !WINDOW_HPP_ */
