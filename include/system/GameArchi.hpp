/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** GameArchi
*/

#ifndef GAMEARCHI_HPP_
#define GAMEARCHI_HPP_

#include "system/gameStates/SGamePlay.hpp"

namespace rtype {
    class GameArchi {
        public:
            GameArchi();
            ~GameArchi();
            void CreateEntities(std::string filename, sf::Vector2f pos, sf::Vector2f scale);
            void MakeEntityMovable(sf::Sprite &asset);
            void CreateWindow(sf::VideoMode mode, std::string name);
            bool UpdateEvent(void);
            bool HandleEvent(const sf::Event::EventType &type);
            void CloseWindow(void);
            void ClearWindow(void);
            void DisplayWindow(void);
            bool IsOpen(void);
            void GameRun(void);
            void End(void);
            void Menu(void);
            void CreateText(std::string name, int size, std::string fontpath, sf::Vector2f pos, sf::Color);
            void CreateBackground(std::string filename);
            sf::Clock winClock;
            sf::RenderWindow window;

        protected:
        private:
            sf::Texture texture;
            sf::VideoMode window_mode;
            std::string window_name;
            sf::Event win_event;
    };
}

#endif /* !GAMEARCHI_HPP_ */
