/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Bullets
*/

#include "../include/Components/Bullets.hpp"

Bullets::Bullets()
{
}

Bullets::~Bullets()
{
}

void Bullets::SetBullets(float radius, sf::Vector2f velocity, float maxSpeed)
{
    this->bullet_maxSpeed = maxSpeed;
    this->bullet_velocity = velocity;
    this->bullet_rect.setRadius(radius);
    this->bullet_rect.setFillColor(sf::Color::Red);
}

void Bullets::Shooting(sf::Sprite sprite)
{
    sf::Vector2f playerpos = sf::Vector2f(sprite.getPosition().x + 100, sprite.getPosition().y + 17);
    sf::Vector2f aimDir = sf::Vector2f(sprite.getPosition().x, 0.f);
    sf::Vector2f aimDirNorm = aimDir / sqrtf32(pow(aimDir.x, 2) + pow(aimDir.y, 2));
    std::vector<Bullets> bullets;
    Bullets b1;
    sf::RenderWindow win;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        this->bullet_rect.setPosition(playerpos);
        this->bullet_velocity = aimDirNorm * this->bullet_maxSpeed;
        bullets.push_back(Bullets(b1));
    }
    for (size_t i = 0; i < bullets.size(); i++) {
        bullets[i].bullet_rect.move(bullets[i].bullet_velocity);
        if (bullets[i].bullet_rect.getPosition().x < 0 || bullets[i].bullet_rect.getPosition().x > win.getSize().x || bullets[i].bullet_rect.getPosition().y < 0 || bullets[i].bullet_rect.getPosition().y > win.getSize().y)
            bullets.erase(bullets.begin() + i);
    }
    for (size_t i = 0; i < bullets.size(); i++) {
        win.draw(bullets[i].bullet_rect);
    }
}