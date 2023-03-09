/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** EntitiesManager
*/

#ifndef ENTITIESMANAGER_HPP_
#define ENTITIESMANAGER_HPP_

#include "Engine/Engine.hpp"
#include "Components/IComponents.hpp"
#include "Utils/SparseArray.hpp"
#include <array>
#include <vector>

namespace rtype::entities {

    static int8_t idx;
    static int8_t idxM;
    class Entity {
        public:
            Entity() {};
            ~Entity() {};

            Entity(rtype::components::Component *compn)
            {
                addComponent(compn);
            };

            void addComponent(rtype::components::Component *newComp) {
                this->comps.addElement(newComp);
                // comps.addElement(newComp);
            }

            int getIndex(int k)
            {
                auto tmp = this->comps.getList();
                for (int i = 0; i < tmp.size(); i++) {
                    if (tmp[i]->getId() == k)
                        return i;
                }
                return -1;
            }

            void removeComp(int8_t id)
            {
                int idx = getIndex(id);
                if (idx == -1)
                    comps.removeElem(idx);
                return;
            }
        protected:
            Utils::SparseArray<rtype::components::Component*, 100> comps;
    };

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
            sf::Sprite CreateMobs(std::string filename, sf::Vector2f pos, sf::Vector2f scale);
            /*
            * @brief Create an entity with the fonction CreateEntities with an ID, this fonction is used for multiplayer games
            * @param fpath path to your asset
            * @param pos the position of your entity in the window
            * @param scale his scale in the window
            */
            void NewEntity(std::string fpath, sf::Vector2f pos, sf::Vector2f scale);
            void NewMobs(std::string fpath, sf::Vector2f pos, sf::Vector2f scale);

            std::list<int8_t> getIDs() {
                return IDs;
            };

            std::list<int8_t> getIDsM() {
                return IDsM;
            };

            void setPId(int id) { this->pId = id;}
            int8_t getPId() {return this->pId;}

            std::array<sf::Sprite, 100> getEntitiesList() {
                return this->entities;
            };

            sf::Sprite &getSprite(int8_t id) {
                //check if valid
                return this->entities[id];
            };

            sf::Sprite &getSpriteM(int8_t id) {
                //check if valid
                return this->entitiesM[id];
            };

            // void draw(sf::RenderWindow &w)
            // {
            //     this->comps.back()->draw(w);
            // }

            // void NewEntity2(std::string fpath, sf::Vector2f pos, sf::Vector2f scale)
            // {
            //     ent.back().addComponent(new rtype::components::DefaultComp(fpath, pos, scale, true));
            //     return;
            // }

            /**
             * @brief This function draw all the entities
             */
            // void update(sf::RenderWindow &w)
            // {
            //     for (auto &e : entities) {
            //         e.draw(w);
            //     }
            //     return;
            // }

            // /**
            //  * @brief This function draw all the entities
            //  */
            // void handleEvent(rtype::engine::Event &handler)
            // {
            //     for (auto &e : entities) {
            //         e.handleEvent(handler);
            //     }
            //     return;
            // }

        private:
            int8_t pId; //player ID used to get local input relative to player pos in entity array
            std::array<sf::Sprite, 100> entities;
            std::array<sf::Sprite, 100> entitiesM;
            Utils::SparseArray<rtype::components::Component*, 100> comps;
            sf::Texture texture;
            sf::Texture textureMobs;
            std::list<int8_t> IDs;
            std::list<int8_t> IDsM;
            sf::RenderWindow window;
            std::vector<Entity> ent;
    };
};

#endif /* !ENTITIESMANAGER_HPP_ */
