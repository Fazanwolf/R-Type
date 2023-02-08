/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Bullets
*/

#ifndef BULLETS_HPP_
#define BULLETS_HPP_

#include "Engine.hpp"
#include "math.h"

namespace rtype::components {

    enum BulletType
    {
        SIMPLE, //small fireball
        ROCKET, //rocket
        BEAM, //laser beam
        NOVA //bigass fireball
    };

    class Bullets {
        public:
            Bullets();
            ~Bullets();
            sf::CircleShape CreateBullet(sf::Vector2f pos);
            std::list<sf::CircleShape> ShootBullet(sf::Sprite sprite);
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

            void drawBullets(sf::Window &win);
            bool update(sf::FloatRect bounds);

            // void SetBullets(float radius, sf::Vector2f velocity, float maxSpeed);
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

#endif /* !BULLETS_HPP_ */
