/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** EntitiesManager
*/

#include "../include/Entities/EntitiesManager.hpp"

EntitiesManager::EntitiesManager()
{
}

EntitiesManager::~EntitiesManager()
{
}

sf::Sprite EntitiesManager::CreateEntitie(std::string filename, sf::Vector2f pos, sf::Vector2f scale)
{
    if (!texture.loadFromFile(filename))
        std::cout << "error" << std::endl;
    asset.setTexture(texture);
    asset.setPosition(pos);
    asset.scale(scale);

    return asset;
}