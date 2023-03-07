/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Bullets
*/

#pragma once

#include "Engine/Engine.hpp"
#include "IComponents.hpp"
#include "math.h"

/**
* @brief This namespace is for herite from components
*/
namespace rtype::components {

    /**
    * @brief This enum is for all type of bullet in the game
    */
    enum BulletType
    {
        SIMPLE, //small fireball
        ROCKET, //rocket
        BEAM, //laser beam
        NOVA //bigass fireball
    };

    /**
    * @brief This class is the base class for all the bullets
    */
    class Bullets : public Component {
        public:
            /**
            * @brief Constructor for class Bullets
            */
            Bullets();

            /**
            * @brief Destructor for class Bullets
            */
            ~Bullets();

            /**
            * @brief Function to create a bullet at a pos
            *
            * @param pos Position of the bullet to start
            *
            * @return Return a circle shape
            */
            sf::CircleShape CreateBullet(sf::Vector2f pos);

            /**
            * @brief Function to shoot a bullet
            *
            * @param id Id of the entitie who shoot
            * @param sprite Sprite of the entitie who shoot
            *
            * @return Return True if bullet shoot
            */
            bool ShootBullet(int id, sf::Sprite sprite);

            /**
            * @brief Function to shoot a bullet for the server
            *
            * @param id Id of the entitie who shoot
            * @param sprite Sprite of the entitie who shoot
            *
            * @return Return True if bullet shoot
            */
            bool ServerShootBullet(int id, sf::Sprite sprite);

            /**
            * @brief Function to know if a bullet collide to somethings
            *
            * @param bounds bounds to check if collide
            *
            * @return Return a true if collide ans false if not
            */

            bool collided(sf::FloatRect bounds)
            {
                for (auto& ammo : this->bullets_list)
                {
                    if (ammo.getGlobalBounds().intersects(bounds)) {
                        // bullets_list.remove(ammo);
                        return true;
                    }
                }
                return false;
            };

            /**
            * @brief Function to draw a bullet on a window
            *
            * @param win Window of the game
            */
            void draw(sf::RenderWindow &win) override {
                for (auto &b : bullets_list) {
                    win.draw(b);
                }
            }

            /**
            * @brief Function to update the bullet
            *
            * @param bounds bounds to check if collide
            * 
            * @return Return False when finish
            */
            bool update(sf::FloatRect bounds);

            // void SetBullets(float radius, sf::Vector2f velocity, float maxSpeed);

            /**
            * @brief Function to get the list of bullet
            *
            * @return Return a circle shape list
            */
            std::list<sf::CircleShape> getBulletList() {return this->bullets_list;};

        private:
            sf::Clock selfClock;
            sf::Time mtime;
            std::int8_t ownerID;
            std::list<sf::CircleShape> bullets_list;
            sf::Vector2f bullet_velocity;
            sf::Vector2f bullet_pos;
            float bullet_maxSpeed;
    };
}
