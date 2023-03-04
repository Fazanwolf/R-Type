/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** EntitiesManager
*/

#include "Entities/EntitiesManager.hpp"
#include "system/GameEngine.hpp"
#include <vector>

using namespace rtype::entities;

EntitiesManager::EntitiesManager()
{
    this->setPId(-1);
}

EntitiesManager::~EntitiesManager()
{
}

void EntitiesManager::initTexture(std::string fpath, int i)
{
    if (!textures[i].loadFromFile(fpath))
        std::cout << "error" << std::endl;
}

void EntitiesManager::initTextures(std::vector<std::string> list)
{

}

sf::Sprite EntitiesManager::CreateEntitie(std::string filename, bool isEnemie, int i)
{
    sf::Sprite asset;
    initTexture(filename, i);
    if (isEnemie == false) {
        asset.setTexture(textures[i]);
        asset.setPosition(100, 100);
        asset.scale({0.1, 0.1});
    } else {
        asset.setTexture(textures[i]);
        float yveltal = rand() % 620;
        asset.setPosition(this->window.getSize().x + 500.f, yveltal);
        asset.scale({0.3, 0.3});
    }

    return asset;
}

void EntitiesManager::NewEntity(std::string fpath, bool isEnemie, int i)
{
    if (isEnemie == false) {
        this->entities[idx] = this->CreateEntitie(fpath, false, i);
        IDs.push_back(idx);
        idx++;
    } else {
        this->entitiesE[idxE] = this->CreateEntitie(fpath, true, i);
        IDs.push_back(idxE);
        idxE++;
    }
}

void EntitiesManager::updateEnemies(std::string fpath, bool isEnemie, int nbE, int i)
{
    components::Bullets bull;

	// Updating the timer for enemy spawning
	if (nbE > this->enemySpawnMax) {
        int iSecret = rand() % 10 + 1;
        if (iSecret==1) {
            this->NewEntity(fpath, isEnemie, i);
	        	this->enemySpawnMax++;
        }
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
