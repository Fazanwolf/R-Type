/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** EntitiesManager
*/

#ifndef ENTITIESMANAGER_HPP_
#define ENTITIESMANAGER_HPP_

#include "Engine.hpp"

class EntitiesManager {
    public:
        EntitiesManager();
        ~EntitiesManager();
        sf::Sprite CreateEntitie(std::string filename, sf::Vector2f pos, sf::Vector2f scale);

    protected:
    private:
        sf::RenderWindow window;
        sf::Sprite asset;
        sf::Texture texture;
};

#endif /* !ENTITIESMANAGER_HPP_ */
