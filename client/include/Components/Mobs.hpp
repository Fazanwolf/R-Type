/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Mobs
*/

#pragma once

#include "Engine/Engine.hpp"
#include <math.h>

namespace rtype::components {

    class Mobs {
        public:
            Mobs(sf::Vector2f position, sf::Texture& texture, bool isAI) : isAI(isAI) {
                this->sprite.setTexture(texture);
                this->sprite.setPosition(position);
            }
            void update(sf::Vector2f playerPosition) {
                if (isAI) {
                    this->sprite.move(moveAIChase(playerPosition, this->sprite.getPosition()));
                } else {
                    this->sprite.move(moveAIRandom(chooseDirectionRandom(false)) * 1.5f);
                }
                /* If an enemy is detected on a player, shoot */
                if (this->sprite.getPosition().y == playerPosition.y) {
                    printf("%f\n", this->sprite.getPosition().x);
                }
            }
            sf::Sprite& getSprite() {
                return this->sprite;
            }
        private:
            sf::Sprite sprite;
            bool isAI;
            int chooseDirectionRandom(bool isEnemie) {
                switch (rand() % 3) {
                    case 0:
                        return 0; // MV_UP
                    case 1:
                        if (isEnemie == true)
                            return 1; // MV_LEFT
                        else
                            return 2; // MV_RIGHT
                    default:
                        return 3; // MV_DOWN
                }
            }
            sf::Vector2f moveAIRandom(int dir) {
                if (dir == 0)
                    return {-2.f, 0.f};
                else if (dir == 1)
                    return {2.f, 0.f};
                else if (dir == 2)
                    return {0.f, 2.f};
                else if (dir == 3)
                    return {0.f, -2.f};
                return {0.f, 0.f};
            }
            sf::Vector2f normalize(sf::Vector2f vec) {
                float magnitude = sqrtf(vec.x * vec.x + vec.y * vec.y);
                if (magnitude != 0) {
                    vec.x /= magnitude;
                    vec.y /= magnitude;
                }
                return vec;
            }
            sf::Vector2f moveAIChase(sf::Vector2f posPlayer, sf::Vector2f posEnemi) {
                sf::Vector2f distance = ((posPlayer)- posEnemi);
                return normalize(distance) * 2.f;
            }
    };
}