/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** EntitiesManager
*/

#pragma once

#include "Engine/Engine.hpp"
#include "Components/IComponents.hpp"
#include "Utils/SparseArray.hpp"

/**
 * @brief This namepace is used to manage all the entities in the game
 */
namespace rtype::entities {

    class Entity
    {
        public:
            Entity() {};
            
            Entity(int8_t idx, rtype::components::Component *compn)
            {
                this->Id = idx;
                addComponent(compn);
            };

            Entity(int8_t idx)
            {
                this->Id = idx;
            }

            ~Entity() {};

            //setter
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

            //getter
            int8_t getEntityId() { return this->Id; }

            /**
             * @brief This function draw all the entities
             */
            void updates(sf::RenderWindow &w)
            {
                for (int i : comps.getUsedId()) {
                    comps.getList()[i]->update();
                // for (auto &e : comps.getList() ) {
                    // e->update();
                }
                return;
            }

            /**
             * @brief This function handle Event for all the entities
             */
            void handleEvent(rtype::engine::Event &ev)
            {
                for (int i : comps.getUsedId()) {
                   comps.getList()[i]->handleEvent(ev);
                }
                return;
            }
            void draw(sf::RenderWindow &w)
            {
                this->comps.back()->draw(w);
                // this->comps.back().draw(w);

            //     for (auto cmp : comps.getList()) {
                    
            //         cmp.pName();
            //         cmp->draw(w);
            //     }
            }

            // sf::Transformable getDrawable() {
            //     return comps.front()->getDrawable();
            // }

        protected:
            int8_t Id;
            Utils::SparseArray<rtype::components::Component*, 100> comps;
            //rtype::SparseArray<rtype::components::Component*> comps;
        
    };

    static int8_t idx;
    static int8_t e_idx;
    static int8_t idxmobs;
    /**
    * @brief This class create an entity and set it a sprite, set up the position of the entity and his scale
    */
    class EntitiesManager {
        public:
            EntitiesManager();

            EntitiesManager(int id);

            ~EntitiesManager() = default;

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
             * @brief This function is used to get the list of all the entities
             * @return Return a list of all the entities
             */

            void NewMobs(std::string fpath, sf::Vector2f pos, sf::Vector2f scale);

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
             * @brief This function is used to get an entity
             * @param id The id of the entity
             * @return Return entity
             */
            Entity &getEntity(int8_t id) {
                //check if valid
                for (auto &e : this->entities) {
                    if (e.getEntityId() == id)
                        return e;
                }
            };

            /**
             * @brief This function draw all the entities
             */
            void draw(sf::RenderWindow &w)
            {
                for (auto &e : entities) {
                    e.draw(w);
                }
                return;
            }

            /**
             * @brief This function draw all the entities
             */
            void update(sf::RenderWindow &w)
            {
                for (auto &e : entities) {
                    e.draw(w);
                }
                return;
            }

            /**
             * @brief This function draw all the entities
             */
            void handleEvent(rtype::engine::Event &handler)
            {
                for (auto &e : entities) {
                    e.handleEvent(handler);
                }
                return;
            }

            // /**
            //  * @brief Get the Texture Vector object
            //  * 
            //  * @return Return std::vector<sf::Texture> 
            //  */
            // std::vector<sf::Texture> getTextureVector() { return this->textures;}

            void NewEntity(std::vector<rtype::components::Component> components)
            {
                std::cout<<entities.size()<<"\n";
                // entities.push_back(Entity(e_idx, components));
                e_idx = e_idx+1;
                return;
            }

            /**
             * @brief 
             * 
             * @param tex
             * @param pos 
             * @param size
             */
            void NewEntity(sf::Texture &tex, sf::Vector2f pos, sf::Vector2f size)
            {
                entities.push_back(Entity(e_idx));
                entities.back().addComponent(new rtype::components::DefaultComp(tex, pos, size, true));
                e_idx = e_idx+1;
                return;
            }

            /**
             * @brief 
             * 
             * @param fpath 
             * @param pos 
             * @param scale 
             */
            void NewEntity(std::string fpath, sf::Vector2f pos, sf::Vector2f scale)
            {
                entities.push_back(Entity(e_idx));
                entities.back().addComponent(new rtype::components::DefaultComp(fpath, pos, scale, true));
                e_idx = e_idx+1;
                return;
            }

            // sf::Transformable getLocalPlayer() {
            //     for (auto e : entities) {
            //         if (e.getEntityId() == pId)
            //             return e.getDrawable();
            //     }
            // }

        private:
            std::vector<int8_t> pServerIds;
            int8_t pId; //player ID used to get local input relative to player pos in entity array
            sf::RenderWindow window;
            std::vector<Entity> entities;

    };
}
