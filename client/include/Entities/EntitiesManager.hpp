/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** EntitiesManager
*/

#ifndef ENTITIESMANAGER_HPP_
#define ENTITIESMANAGER_HPP_

#include "../Engine/Engine.hpp"
#include "../Components/IComponents.hpp"
#include <array>
#include <vector>
#include <utility>

/**
 * @brief This namepace is used to manage all the entities in the game
 */
namespace rtype::entities {

    class Entity
    {
        public:
            Entity() {};

            /**
             * @brief Construct a new Entity object with a new component
             *
             * @param idx index of the entity
             * @param compn add a new component to the entity
             */
            Entity(int8_t idx, rtype::components::Component compn)
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
            void addComponent(rtype::components::Component newComp) {
                comps.addElem(newComp);
            }

            /**
             * @brief Get the Index object
             *
             * @param k
             * @return int
             */
            int getIndex(int k)
            {
                auto tmp = this->comps.getList();
                for (int i = 0; i < tmp.size(); i++) {
                    if (tmp[i].getId() == k)
                        return i;
                }
                return -1;
            }

            /**
             * @brief Remove the component
             *
             * @param id
             */
            void removeComp(int8_t id)
            {
                int idx = getIndex(id);
                if (idx == -1)
                    comps.removeElem(idx);
                return;
            }

            //getter

            /**
             * @brief Get the entity id
             *
             * @param id
             * @return an id of entity
             */
            int8_t getEntityId() { return this->Id; }

            /**
             * @brief draw on the window
             *
             * @param id
             */
            void draw(sf::RenderWindow &w)
            {
                for (auto &cmp : comps.getList()) {
                    cmp.printSMthing("fuck me\n");
                    cmp.draw(w);
                    std::cout<<"fuck this\n";
                }
            }

        protected:
            int8_t Id;
            rtype::SparseArray<rtype::components::Component> comps;
    };

    static int8_t idx;
    static int8_t e_idx;
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

            /**
             * @brief This function is used to set the player ID
             */
            void setPId(int id) { this->pId = id;}

            /**
             * @brief This function is used to get the player ID
             * @return Return the player ID
             */
            int8_t getPId() {return this->pId;}

            int8_t getEId() {
                return e_idx;
            }

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
            // sf::Sprite &getSprite(int8_t id) {
            //     //check if valid
            //     return this->entities[id];
            // };

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
                std::cout<<entities.size()<<" entity(ies)\n";
                return;
            }

            void NewEntity(sf::Texture &tex, sf::Vector2f pos, sf::Vector2f size)
            {
                std::cout<<entities.size()<<"\n";
                entities.push_back(Entity(e_idx));
                entities.back().addComponent(rtype::components::DefaultComp(tex, pos, size));
                std::cout<<"allllllllllllllllllllllllllllll" << std::endl;
                e_idx = e_idx+1;
                std::cout<<entities.size()<<" entity(ies)\n";
                return;
            }

        private:
            int8_t pId; //player ID used to get local input relative to player pos in entity array
            sf::RenderWindow window;
            std::vector<Entity> entities;

    };
};

#endif /* !ENTITIESMANAGER_HPP_ */
