#ifndef _MOB_HPP_
#define _MOB_HPP_

#include "Engine/Engine.hpp"
#include "Components/IComponents.hpp"
#include <math.h>
#include <vector>

namespace rtype::components {

    class Mob {
        public:
            Mob() {};
            ~Mob() {};
            sf::Vector2f playerPos;    
            sf::Vector2f mobPos;    
            sf::Sprite spriteMob;
            sf::Sprite spriteBullet;
            sf::Sprite spritePlayer;
            sf::Texture texture;

            void init(sf::Vector2f mob, sf::Vector2f player, std::string TextureMob){
                playerPos = player;
                mobPos = mob;
                // this->spritePlayer = spritePlayer;
                texture.loadFromFile(TextureMob);
                spriteMob.setTexture(texture);
                spriteMob.setPosition(mobPos);
            }
            void update() {
                this->spriteMob.move(moveAIChase({0,30}, spriteMob.getPosition()));
                if (this->spriteMob.getPosition().y == spritePlayer.getPosition().y) {
                        // bull.CreateBullet(this->sprite.getPosition());

                        // printf("%f\n", this->sprite.getPosition().x);
                    }
            }
            void draw(sf::RenderWindow& window) {
                window.draw(spriteMob);
            }
        private:
            sf::Vector2f normalize(sf::Vector2f vec) {
                float magnitude = sqrtf(vec.x * vec.x + vec.y * vec.y);
                if (magnitude != 0) {
                    vec.x /= magnitude;
                    vec.y /= magnitude;
                }
                return vec;
            }

            sf::Vector2f moveAIChase(sf::Vector2f posPlayer, sf::Vector2f posEnemi)
            {
                sf::Vector2f distance = ((posPlayer)- posEnemi);

                return normalize(distance) * 2.f;
            }

    };
}

#endif /* _MOB_HPP_ */