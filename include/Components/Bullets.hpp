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

class Bullets {
    public:
        Bullets();
        ~Bullets();
        void SetBullets(float radius, sf::Vector2f velocity, float maxSpeed);
        void Shooting(sf::Sprite sprite);

    protected:
    private:
        sf::CircleShape bullet_rect;
        sf::Sprite bullet_asset;
        sf::Vector2f bullet_velocity;
        sf::Vector2f bullet_pos;
        float bullet_maxSpeed;
};

#endif /* !BULLETS_HPP_ */
