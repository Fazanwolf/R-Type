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
    // Check if index is empty
    // idx++;
    if (!textures[i].loadFromFile(fpath))
        std::cout << "error" << std::endl;
}

void EntitiesManager::initTextures(std::vector<std::string> list)
{

}

sf::Sprite EntitiesManager::CreateEntitie(std::string filename, bool isEnemie)
{
    sf::Sprite asset;

    // if (!texture.loadFromFile(filename))
    //     std::cout << "error" << std::endl;
    if (isEnemie == false) {
        asset.setTexture(textures[0]);
        // asset.setTexture(texture);
        asset.setPosition(100, 100);
        asset.scale({0.1, 0.1});
    } else {
        asset.setTexture(textures[1]);
        // asset.setTexture(texture);
        float yveltal = rand() % 620;
        asset.setPosition(this->window.getSize().x + 500.f, yveltal);
        asset.scale({0.3, 0.3});
    }

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

void EntitiesManager::updateEnemies(std::string fpath, bool isEnemie, int nbE)
{
    components::Bullets bull;

	// Updating the timer for enemy spawning
	if (nbE >= this->enemySpawnMax) {
        // Timer du bled 1 chance sur 10 de spawn enemie
        switch (rand() % 10) {
	    case 0:
	    	break;
        case 1:
	    	break;
        case 2:
	    	break;
        case 3:
	    	break;
        case 4:
	    	break;
        case 5:
	    	break;
        case 6:
	    	break;
        case 7:
	    	break;
        case 8:
	    	break;
	    default:
	    	this->NewEntity(fpath, isEnemie);
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
