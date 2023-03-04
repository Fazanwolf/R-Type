/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** EntitiesManager
*/

#include "Entities/EntitiesManager.hpp"
#include "system/GameEngine.hpp"

using namespace rtype::entities;

EntitiesManager::EntitiesManager()
{
    this->setPId(-1);
}

EntitiesManager::~EntitiesManager()
{
}

sf::Sprite EntitiesManager::CreateEntitie(std::string filename, bool isEnemie)
{
    sf::Sprite asset;

    if (!texture.loadFromFile(filename))
        std::cout << "error" << std::endl;
    asset.setTexture(texture);
    if (isEnemie == false) {
        asset.setPosition(100, 100);
    } else {
        float yveltal = rand() % 620;
        asset.setPosition(this->window.getSize().x + 500.f, yveltal);
    }
    asset.scale({0.3, 0.3});

    return asset;
}

void EntitiesManager::NewEntity(std::string fpath, bool isEnemie)
{
    if (isEnemie == false) {
        this->entities[idx] = this->CreateEntitie(fpath, false);
        IDs.push_back(idx);
        idx++;
    } else {
        this->entitiesE[idxE] = this->CreateEntitie(fpath, true);
        IDs.push_back(idxE);
        idxE++;
    }
}

void EntitiesManager::updateEnemies(std::string fpath, bool isEnemie)
{
	// Updating the timer for enemy spawning
	if (50 >= this->enemySpawnMax) {
		// Spawn the enemy and reset the timer
		this->NewEntity(fpath, isEnemie);
		this->enemySpawnMax++;
	}

	// Moving and updating enemies
	for (int i = 0; i < this->entitiesE.size(); i++) {
		// Movement
		this->entitiesE[i].move(-10.f, 0.f);
		// Si Enemie va trop a gauche = kill enemies
		if (this->entitiesE[i].getPosition().x < -50.f) {
			this->entitiesE[i].setScale(sf::Vector2f(0,0));
		}
	}
}
