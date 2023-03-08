/*
** EPITECH PROJECT, 2023
** B-CPP-500-RUN-5-2-rtype-lucas.miranville
** File description:
** Bullets
*/

#include "Components/Bullets.hpp"

using namespace rtype::components;

Bullets::Bullets()
{
}

Bullets::~Bullets()
{
}

sf::CircleShape Bullets::CreateBullet(sf::Vector2f pos)
{
    sf::CircleShape bullet;
    bullet.setFillColor(sf::Color::Red);
    bullet.setOutlineColor(sf::Color::White);
    bullet.setPosition(pos);
    bullet.setRadius(10.f);
    return bullet;
}

bool Bullets::ShootBullet(int id, sf::Sprite sprite)
{
    sf::Vector2f newPlaypos = sf::Vector2f(sprite.getPosition().x + 10, sprite.getPosition().y);
    std::list<sf::CircleShape> bullets = this->bullets_list;
    if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) && id == 1)
        || (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && id == 0 ) )
    {
        bullets.push_back(CreateBullet(newPlaypos));
        this->bullets_list = bullets;
        return true;
    }
    return false;
}

bool Bullets::ServerShootBullet(int id, sf::Sprite sprite)
{
    sf::Vector2f newPlaypos = sf::Vector2f(sprite.getPosition().x + 10, sprite.getPosition().y);
    std::list<sf::CircleShape> bullets = this->bullets_list;
    bullets.push_back(CreateBullet(newPlaypos));
    this->bullets_list = bullets;
    return true;
}

bool Bullets::update(sf::FloatRect bounds)
{
    if (!bullets_list.empty())
    {
        for (auto &ammo : bullets_list)
        {
            ammo.move(bullet_velocity);
            if (collided(bounds))
                return true;
            ammo.move(sf::Vector2f{10, 0});
        }
    }
    return false;
}

bool Bullets::update(sf::CircleShape shape)
{
    if (!bullets_list.empty())
    {
        for (auto &ammo : bullets_list)
        {
            ammo.move(bullet_velocity);
            if (collided(shape))
                return true;
            ammo.move(sf::Vector2f{10, 0});
        }
    }
    return false;
}