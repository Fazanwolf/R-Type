/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** EntitiesManager
*/

#include "Entities/EntitiesManager.hpp"

using namespace rtype::entities;

EntitiesManager::EntitiesManager()
{
    this->setPId(-1);
}

EntitiesManager::EntitiesManager(int id)
{
    this->setPId(id);
}

sf::Sprite EntitiesManager::CreateEntitie(std::string filename, sf::Vector2f pos, sf::Vector2f scale)
{
    // sf::Sprite asset;

    // if (!texture.loadFromFile(filename))
    //     std::cout << "error" << std::endl;
    // asset.setTexture(texture);
    // asset.setPosition(pos);
    // asset.scale(scale);

    // return asset;
}

sf::Sprite EntitiesManager::CreateMobs(std::string filename, sf::Vector2f pos, sf::Vector2f scale)
{
    // sf::Sprite assetMobs;

    // if (!texture.loadFromFile(filename))
    //     std::cout << "error" << std::endl;
    // assetMobs.setTexture(textureMobs);
    // assetMobs.setPosition(pos);
    // assetMobs.scale(scale);

    // return assetMobs;
}

// void EntitiesManager::NewEntity(std::string fpath, sf::Vector2f pos, sf::Vector2f scale)
// {
//     // this->entities[idx] = this->CreateEntitie(fpath, pos, scale);
//     // IDs.push_back(idx);
//     // idx++;
// }

void EntitiesManager::NewMobs(std::string fpath, sf::Vector2f pos, sf::Vector2f scale)
{
    // this->mobs[idxmobs] = this->CreateMobs(fpath, pos, scale);
    // IDsMobs.push_back(idxmobs);
    // idxmobs++;
}
