/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** EntitiesManager
*/

#ifndef ENTITIESMANAGER_HPP_
#define ENTITIESMANAGER_HPP_

#include "../Engine/Engine.hpp"
#include <array>
#include <vector>

namespace rtype::entities {

    static int8_t idx;
    class EntitiesManager {
        public:
            EntitiesManager();
            ~EntitiesManager();

            /*
            * @brief Create an entity and set it a sprite, set up the position of the entity and his scale
            * @param filemane path to your asset
            * @param pos the position of your entity in the window
            * @param scale his scale in the window
            * @return return a sprite
            */
            sf::Sprite CreateEntitie(std::string filename, sf::Vector2f pos, sf::Vector2f scale);

            /*
            * @brief Create an entity with the fonction CreateEntities with an ID, this fonction is used for multiplayer games
            * @param fpath path to your asset
            * @param pos the position of your entity in the window
            * @param scale his scale in the window
            */
            void NewEntity(std::string fpath, sf::Vector2f pos, sf::Vector2f scale);

            std::list<int8_t> getIDs() {
                return IDs;
            };

            void setPId(int id) { this->pId = id;}
            int8_t getPId() {return this->pId;}

            std::array<sf::Sprite, 100> getEntitiesList() {
                return entities;
            };

            sf::Sprite &getSprite(int8_t id) {
                //check if valid
                return this->entities[id];
            };

            void Draw()
            {
                return;
            }

        private:
            int8_t pId; //player ID used to get local input relative to player pos in entity array
            std::array<sf::Sprite, 100> entities;
            sf::Texture texture;
            std::list<int8_t> IDs;
            sf::RenderWindow window;
    };
};

#endif /* !ENTITIESMANAGER_HPP_ */
