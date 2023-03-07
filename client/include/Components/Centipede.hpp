#ifndef _CENTIPEDE_HPP_
#define _CENTIPEDE_HPP_

#include "Engine/Engine.hpp"
#include "Components/IComponents.hpp"
#include "math.h"
#include <vector>
#include <cmath>

namespace rtype::components {

const int BLOCK_SIZE = 15;
const float BLOCK_SPEED = 1;

    class Block {
    public:
        sf::CircleShape shape;
        sf::Vector2f velocity;

        Block(float startX, float startY) {
            shape.setRadius(BLOCK_SIZE);
            shape.setPosition(startX, startY);
            shape.setFillColor(sf::Color::Green);
            velocity.x = -BLOCK_SPEED; //change the direction of the centipede
        }

        void update() {
            // shape.move(velocity.x, velocity.y + sin(shape.getPosition().x / 500) * 0.1);
            shape.move(velocity.x, velocity.y + sin(shape.getPosition().x / 50));
        }
    };

// Centipede class
    class Centipede {
    public:
        std::vector<Block> blocks;
        Centipede() {}

        void Centipedeinit(int startX, int startY, int numBlocks) {
            for (int i = 0; i < numBlocks; i++) {
                Block block(startY + (i * BLOCK_SIZE), startX); // Change the starting position to the right
                blocks.push_back(block);
            }
        }
        void update() {
            for (int i = 0; i < blocks.size(); i++) {
                blocks[i].update();

            }
        }

        void draw(sf::RenderWindow& window) {
            for (int i = 0; i < blocks.size(); i++) {
                window.draw(blocks[i].shape);
            }
        }
    };
}



#endif /* _CENTIPEDE_HPP_ */