/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** EntitiesManager
*/

#pragma once

#include "Engine/Engine.hpp"
#include "Components/IComponents.hpp"
#include <array>
#include <vector>

/**
 * @brief This namepace is used to manage all the entities in the game
 */
namespace rtype::entities {

    static int8_t idx;
    static int8_t idxmobs;
    /**
    * @brief This class create an entity and set it a sprite, set up the position of the entity and his scale
    */
    class EntitiesManager {
        public:
            EntitiesManager();
            ~EntitiesManager();

            /**
            * @brief Create an entity and set it a sprite, set up the position of the entity and his scale
            * @param filemane path to your asset
            * @param pos the position of your entity in the window
            * @param scale his scale in the window
            * @return return a sprite
            */
            sf::Sprite CreateEntitie(std::string filename, sf::Vector2f pos, sf::Vector2f scale);

            /**
            * @brief Create an entity with the fonction CreateEntities with an ID, this fonction is used for multiplayer games
            * @param fpath path to your asset
            * @param pos the position of your entity in the window
            * @param scale his scale in the window
            * @return return a sprite
            */

            sf::Sprite CreateMobs(std::string filename, sf::Vector2f pos, sf::Vector2f scale);

            /**
             * @brief 
             * 
             * @param fpath 
             * @param pos 
             * @param scale 
             */

            void NewEntity(std::string fpath, sf::Vector2f pos, sf::Vector2f scale);
            /**
             * @brief This function is used to get the list of all the entities
             * @return Return a list of all the entities
             */

            void NewMobs(std::string fpath, sf::Vector2f pos, sf::Vector2f scale);

            std::list<int8_t> getIDs() {
                return IDs;
            };

            std::list<int8_t> getIDsMobs() {
                return IDsMobs;
            };

            /**
             * @brief This function is used to set the player ID
             */
            void setPId(int id) { this->pId = id;}
            /**
             * @brief This function is used to get the player ID
             * @return Return the player ID
             */
            int8_t getPId() {return this->pId;}
            /**
             * @brief This function is used to get the list of all the entities
             * @return Return a list of all the entities
             */
            std::array<sf::Sprite, 100> getEntitiesList() {
                return entities;
            };

            std::array<sf::Sprite, 100> getMobsLists() {
                return mobs;
            }

            /**
             * @brief This function is used to get the sprite of an entity
             * @param id The id of the entity
             * @return Return the sprite of the entity
             */
            sf::Sprite &getSprite(int8_t id) {
                //check if valid
                return this->entities[id];
            };

            sf::Sprite &getSpriteMobs(int8_t id) {
                //check if valid
                return this->mobs[id];
            };

            /**
             * @brief This function draw all the entities
             */
            void Draw()
            {
                return;
            }
            /**
             * @brief Get the Texture Vector object
             * 
             * @return Return std::vector<sf::Texture> 
             */
            std::vector<sf::Texture> getTextureVector() { return this->textures;}
        private:
            int8_t pId; //player ID used to get local input relative to player pos in entity array
            std::vector<>
            std::array<sf::Sprite, 100> entities;
            std::array<sf::Sprite, 100> mobs;
            sf::Texture texture;
            std::vector<sf::Texture> textures;
            std::vector<sf::Texture> texturesMobs;
            sf::Texture textureMobs;
            std::list<int8_t> IDs;
            sf::RenderWindow window;
            std::list<int8_t> IDsMobs;
    };
};
